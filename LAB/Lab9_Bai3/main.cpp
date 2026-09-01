#include "HardDisk.h"
#include "Folder.h"
#include "File.h"
#include "Composite.h"

int main()
{
	DriveComponent* DiskC = new HardDisk();
	cin >> *DiskC;
	
	DriveComponent* folder1 = new Folder();
	DriveComponent* folder2 = new Folder();
	DriveComponent* folder3 = new Folder();
	cin >> *folder1 >> *folder2 >> *folder3;

	DriveComponent* file1 = new File();
	DriveComponent* file2 = new File();
	cin >> *file1 >> *file2;

	DiskC->AddComponent(folder1);
	DiskC->AddComponent(folder2);
	DiskC->AddComponent(folder3);

	folder1->AddComponent(file1);
	folder3->AddComponent(file2);

	cout << *DiskC << endl;
	return 0;
}