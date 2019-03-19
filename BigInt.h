#include <iostream>
#include <string>
const int BSIZE = 1000;

class BigInt {
	//friend BigInt& operator ++ (BigInt&);
	friend bool operator < (const BigInt&, const BigInt&);
	friend std::ostream& operator << (std::ostream&, const BigInt&);
	friend std::istream& operator >> (std::istream&, const BigInt&);
	friend BigInt& operator - (const BigInt&, const BigInt&);
	friend BigInt& operator + (const BigInt&, const BigInt&);
private:
	int data[BSIZE];
	int lenght;
public:
	BigInt();
	BigInt(const std::string);
	int getLenght() const;
	void setData(const int d[BSIZE]);
	void updateLenght();

};