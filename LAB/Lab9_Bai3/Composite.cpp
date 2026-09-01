#include "Composite.h"

DriveComposite::DriveComposite(const DriveComposite& obj) : DriveComponent(obj) {
	for (auto& it : obj.compositeContent) {
		if (it) {
			this->compositeContent.push_back(it->Clone());
		}
	}
}

DriveComposite::~DriveComposite() {
	for (auto& it : compositeContent) {
		delete it;
	}
	compositeContent.clear();
}

DriveComposite& DriveComposite::operator = (const DriveComposite& obj) {
	if (this == &obj) return *this;

	// Don dep tai nguyen
	for (auto& it : compositeContent) {
		delete it;
	}
	compositeContent.clear();

	DriveComponent::operator=(obj);
	for (auto& it : obj.compositeContent) {
		if (it) {
			this->compositeContent.push_back(it->Clone());
		}
	}
	return *this;
}

double DriveComposite::GetSize() const {
	double totalSize = 0;
	for (auto& it : compositeContent) {
		totalSize += it->GetSize();
	}

	return totalSize;
}

bool DriveComposite::AddComponent(DriveComponent* obj) {
	if (obj) {
		compositeContent.push_back(obj);
		return true;
	}
	return false;
}

bool DriveComposite::RemoveComponent(string name) {
	for (int i = 0; i < compositeContent.size(); ++i) {
		if (compositeContent[i]->GetName() == name) {
			delete compositeContent[i];
			compositeContent.erase(compositeContent.begin() + i);
			return true;
		}
	}
	return false;
}
