#include "Number.h"


void Number::getValue(int* v, int size) const{
	for (int i = 0; (i < size && i < 4); i++) {
		v[i] = value_[i];
	}
}
