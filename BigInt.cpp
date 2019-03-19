#include "BigInt.h"

void BigInt::setData(const int d[BSIZE]) {
	for (int i = 0; i < BSIZE; ++i) {
		data[i] = d[i];
	}
}

void BigInt::updateLenght() {
	int i = 0;
	while (data[i] == 0) ++i;
	lenght = BSIZE - i;
	if (lenght == 0) {
		lenght = 1;
	}
}

int BigInt::getLenght() const {
	return lenght;
}

BigInt::BigInt() {
	for (int i = 0; i < BSIZE; ++i) {
		data[i] = 0;
	}
	lenght = 1;
}

BigInt::BigInt(const std::string s) {
	lenght = s.size();
	for (int i = 0; i < BSIZE - lenght; ++i) {
		data[i] = 0;
	}
	for (int i = BSIZE - lenght; i < BSIZE; ++i) {
		data[i] = s[i - BSIZE + lenght] - 48;
	}
}

/*
BigInt& operator ++ (BigInt& a) {
	BigInt c("1");
	BigInt d;
	d = a + c;
	return d;
}
*/

std::ostream& operator << (std::ostream& output, const BigInt& bint) {
	for (int i = BSIZE - bint.getLenght(); i < BSIZE; ++i) {
		std::cout << (bint.data[i]);
	}
	return output;
}

std::istream& operator >> (std::istream& input, BigInt& bint) {
	std::string s;
	std::cin >> s;
	bint = BigInt(s);
	return input;
}

bool operator < (const BigInt& a, const BigInt& b) {
	int i = 0;
	while (a.data[i] == b.data[i] && i < 1000) {
		++i;
	}
	if (i == 1000) { return false; }
	if (a.data[i] >= b.data[i]) { return false; }
	return true;
}

BigInt& operator - (const BigInt& a, const BigInt& b) {
	BigInt c;
	int res[BSIZE];
	int dot = 0;
	if (a < b) {
		BigInt c;
		c = b - a;
		return c;
	}

	else {
		for (int i = BSIZE - 1; i >= 0; --i) {
			if (a.data[i] - b.data[i] - dot >= 0) {
				res[i] = a.data[i] - b.data[i] - dot;
				dot = 0;
			}

			else {
				res[i] = 10 - (b.data[i] + dot - a.data[i]);
				dot = 1;
			}
		}
	}
	c.setData(res);
	c.updateLenght();
	return c;
}

int * BigInt::getData() {
	return data;
}

BigInt& operator + (const BigInt& a, const BigInt& b) {
	BigInt c;
	int res[BSIZE];
	int dot = 0;
	for (int i = BSIZE - 1; i >= 0; --i) {
		if (a.data[i] + b.data[i] + dot < 10) {
			res[i] = a.data[i] + b.data[i] + dot;
			dot = 0;
		}

		else {
			res[i] = a.data[i] + b.data[i] + dot - 10;
			dot = 1;
		}
	}

	c.setData(res);
	c.updateLenght();
	return c;
	

}

int main() {
	std::cout <<  "vvedi 2 chisla >0 dlya raznosti" << "\n";
	BigInt bint1, bint2, res;
	std::cin >> bint1 >> bint2;
	res = bint1 - bint2;
	std::cout << res << " razn po modulu \n";

	std::cout <<  "\n" << "vvedi 2 chisla dlya summi" << "\n";
	std::cin >> bint1 >> bint2;
	res = bint1 + bint2;
	std::cout << res << " summa \n";

	//std::cout << "\n" << "vvedi 1 chislo dlya ++" << "\n";
	//std::cin >> bint1;
	//res = bint1++;
	//std::cout << res << " 1st ++  \n";
	std::cout << "\n" << "vvedi 2 chisla dlya sravneniya" << "\n";
	std::cin >> bint1 >> bint2;
	bool mens;
	mens = bint1 < bint2;
	if (mens) std::cout << "1st < 2st \n";
	else std::cout << "1st >= 2st \n";
	//std::cout << (res < bint1) << " sum < bint1? 0 = no, 1 = yes \n";
}

