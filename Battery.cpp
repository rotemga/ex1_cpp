
#include "Battery.h"
#include <algorithm>
Battery::Battery(int capacity, int conRate, int rachRate) :
capacity(capacity), conRate(conRate), rachRate(rachRate), currentState(0){
}

Battery::~Battery() {
	// TODO Auto-generated destructor stub
}

void Battery::recharge(int times) {
	currentState = std::min(capacity, currentState + times*rachRate);
}

bool Battery::isEmpry() {
	return currentState == 0;
}

bool Battery::isFull() {
	return currentState == capacity;
}

void Battery::reduce(int times) {
	currentState = std::max(0, currentState - times*conRate);
}