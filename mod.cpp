#include "mod.h"

int Mod::getMod() const {
	return model;
}

void Mod::setMod() {
	BigInt current;
	current.setData(getData());
	current.updateLenght();
	while (NULLINT < current) {
		current = current - BIGMOD;
	}
	current.updateLenght();
	int len = current.getLenght();
	int stepen10 = 1;
	int result = 0;
	for (int i = 0; i < len; ++i) {
		result += current.getData[BSIZE - 1 - i] * stepen10;
		++stepen10;
	}
	model = result;
}
