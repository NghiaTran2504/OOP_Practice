#include "MechaFacility.h"
#include "Operator.h"

MechaFacility::~MechaFacility() {
	owner = nullptr;
}

void MechaFacility::setOwner(Operator* op) {
	owner = op;
}