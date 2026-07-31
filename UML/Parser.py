import re
import glob
import os

# ==========================================
# HÀM PARSER V3 - HOÀN HẢO & ỔN ĐỊNH
# ==========================================
def parse_args(args_str):
    """Hàm phụ trợ xử lý lật ngược tham số"""
    if not args_str: return ""
    args_list = args_str.split(',')
    uml_args = []
    for arg in args_list:
        arg = arg.strip()
        default_val = ""
        # Xử lý nếu tham số có giá trị mặc định (vd: targetCar = "")
        if "=" in arg:
            arg, default_val = arg.split("=", 1)
            default_val = " = " + default_val.strip()
        
        arg = arg.strip()
        arg_parts = arg.rsplit(' ', 1)
        if len(arg_parts) == 2:
            uml_args.append(f"{arg_parts[1]}: {arg_parts[0]}{default_val}")
        else:
            uml_args.append(arg + default_val)
    return ", ".join(uml_args)

def parse_method(clean_sig, class_name, access_modifier):
    """Hàm phụ trợ xử lý phương thức"""
    # Xóa phần khởi tạo thừa sau dấu : của Constructor
    if clean_sig.startswith(class_name) and ":" in clean_sig:
        clean_sig = clean_sig.split(':')[0].strip()

    if clean_sig.startswith("~") or clean_sig.startswith(class_name):
        param_match = re.search(r'\((.*?)\)', clean_sig)
        if param_match and param_match.group(1):
            parsed_args = parse_args(param_match.group(1))
            clean_sig = clean_sig.replace(param_match.group(1), parsed_args)
        return f"{access_modifier} {clean_sig}"
    else:
        # Tách chữ const ở cuối hàm (nếu có)
        is_const = ""
        if clean_sig.endswith("const"):
            is_const = " const"
            clean_sig = clean_sig[:-5].strip()
            
        method_match = re.search(r'^([\w\:\<\>\*\&]+(?:\s+[\w\:\<\>\*\&]+)*)\s+(\w+|operator[^\(]+)\s*\((.*)\)', clean_sig)
        if method_match:
            ret_type = method_match.group(1).strip()
            m_name = method_match.group(2).strip()
            args_str = method_match.group(3).strip()
            
            parsed_args = parse_args(args_str)
            return f"{access_modifier} {m_name}({parsed_args}): {ret_type}{is_const}"
        else:
            return f"{access_modifier} {clean_sig}"

def parse_attribute(clean_sig, access_modifier):
    """Hàm phụ trợ xử lý thuộc tính"""
    attr_match = re.search(r'^([\w\:\<\>\*\&]+)\s+(\w+)\s*(=\s*.*)?$', clean_sig)
    if attr_match:
        a_type = attr_match.group(1)
        a_name = attr_match.group(2)
        a_default = attr_match.group(3) if attr_match.group(3) else ""
        return f"{access_modifier} {a_name}: {a_type}{a_default}".strip()
    else:
        return f"{access_modifier} {clean_sig}"

def cpp_to_strict_umlet(cpp_code):
    """Hàm lõi quét dòng mã C++ bằng bộ đếm ngoặc nhọn"""
    cpp_code = re.sub(r'//.*', '', cpp_code) # Xóa comment
    lines = cpp_code.split('\n')
    
    class_name = "UnknownClass"
    attributes = []
    methods = []
    access_modifier = "-" 
    brace_level = 0 # Bộ đếm theo dõi độ sâu của các khối { }

    for line in lines:
        line = line.strip()
        # Bỏ qua các dòng vô dụng
        if not line or line.startswith(("using", "friend", "#")): 
            continue

        # Lấy tên Class
        class_match = re.search(r'^class\s+(\w+)', line)
        if class_match:
            class_name = class_match.group(1)

        # Cắt các cụm {} nằm gọn trên 1 dòng
        line_no_pairs = re.sub(r'\{.*?\}', '', line)
        
        opens = line_no_pairs.count('{')
        closes = line_no_pairs.count('}')
        new_brace_level = brace_level + opens - closes

        # BỎ QUA MỌI THỨ nếu đang ở sâu bên trong thân hàm (brace_level > 1)
        if brace_level > 1:
            brace_level = new_brace_level
            continue

        # Chỉ phân tích khi đang ở tầng của Class (brace_level == 1)
        if brace_level == 1 or (brace_level == 0 and new_brace_level == 1):
            clean_sig = line_no_pairs.replace('{', '').replace('}', '').strip()
            clean_sig = clean_sig.rstrip(';')
            
            if not clean_sig or class_match: pass
            elif "public:" in clean_sig: access_modifier = "+"
            elif "private:" in clean_sig: access_modifier = "-"
            elif "protected:" in clean_sig: access_modifier = "#"
            else:
                if "(" in clean_sig and ")" in clean_sig:
                    methods.append(parse_method(clean_sig, class_name, access_modifier))
                else:
                    attributes.append(parse_attribute(clean_sig, access_modifier))
        
        brace_level = new_brace_level

    umlet_text = f"{class_name}\n--\n"
    umlet_text += "\n".join(attributes) + "\n--\n"
    umlet_text += "\n".join(methods)
    return umlet_text

# ==========================================
# KHỞI CHẠY QUÉT TOÀN BỘ FILE .H / .HPP
# ==========================================
def main():
    print("=== TOOL PARSER C++ SANG UMLET V3 ===")
    
    # Định vị chính xác thư mục chứa file .py này
    script_dir = os.path.dirname(os.path.abspath(__file__))
    
    # Tìm tất cả file .h và .hpp trong thư mục đó
    header_files = glob.glob(os.path.join(script_dir, "*.h")) + glob.glob(os.path.join(script_dir, "*.hpp"))
    
    if not header_files:
        print("Lỗi: Không tìm thấy file .h hoặc .hpp nào!")
        print(f"-> Thư mục vừa quét: {script_dir}")
        return
        
    short_names = [os.path.basename(f) for f in header_files]
    print(f"Đã tìm thấy {len(header_files)} file: {', '.join(short_names)}\n")
    
    output_path = os.path.join(script_dir, "UML_Output.txt")
    with open(output_path, "w", encoding="utf-8") as file_out:
        for file_path in header_files:
            file_name = os.path.basename(file_path)
            print(f"Đang xử lý: {file_name}...")
            
            # errors='ignore' để phòng trường hợp file C++ bị mã hóa ANSI/Shift-JIS/Windows-1252
            with open(file_path, "r", encoding="utf-8", errors="ignore") as file_in:
                cpp_content = file_in.read()
                
            umlet_result = cpp_to_strict_umlet(cpp_content)
            
            file_out.write(f"// ===== NỘI DUNG TỪ FILE: {file_name} =====\n")
            file_out.write(umlet_result)
            file_out.write("\n\n\n")
            
    print(f"\nThành công! Kết quả đã ghi vào: {output_path}")

if __name__ == "__main__":
    main()
    input("\nẤn Enter để thoát...")