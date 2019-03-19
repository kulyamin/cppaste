/*
пока не сделан ввод и вывод
скоро будет
*/

#pragma once
#include "BigInt.h"

const int CONSTMOD = 1000;
const std::string MODS = "10000";
const BigInt BIGMOD = MODS;

class Mod: public BigInt {
private:
	int model;
public:
	void setMod();
	int getMod() const;
};

