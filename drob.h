#pragma once
#include <iostream>

using namespace std;

class Drob {
	int x, y;
public:
	Drob(int x = 0, int y = 1) {
		this->setX(x);
		this->setY(y);
	}

	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		(y == 0) ? this->y = 1 : this->y = y;
	}

	int getX() const { return this->x; }
	int getY() const { return this->y; }
	void print() const {
		cout << x << "/" << y << " = " << (double)this->x / this->y << endl;
	}

	Drob& operator+=(const Drob& obj) {
		this->x = this->x * obj.y + this->y * obj.x;
		this->y = this->y * obj.y;
		this->reduce();
		return *this;
	}

	Drob& operator-=(const Drob& obj) {
		this->x = this->x * obj.y - this->y * obj.x;
		this->y = this->y * obj.y;
		this->reduce();
		return *this;
	}

	Drob& operator*=(const Drob& obj) {
		this->x = this->x * obj.x;
		this->y = this->y * obj.y;
		this->reduce();
		return *this;
	}

	Drob& operator/=(const Drob& obj) {
		this->x = this->x * obj.y;
		this->y = this->y * obj.x;
		this->reduce();
		return *this;
	}

	Drob operator+(const Drob& b) {
		return Drob(this->x * b.y + b.x * this->y, this->y * b.y).reduce();
	}

	Drob operator-(const Drob& b) {
		return Drob(this->x * b.y - b.x * this->y, this->y * b.y).reduce();
	}

	Drob operator/(const Drob& b) {
		return Drob(this->x * b.y, this->y * b.x).reduce();
	}

	Drob operator*(const Drob& b) {
		return Drob(this->x * b.x, this->y * b.y).reduce();
	}

	Drob& operator++() {
		this->x += this->y;
		this->reduce();
		return *this;
	}

	Drob& operator++(int) {
		Drob d(this->x, this->y);
		++(*this);
		return d;
	}

	Drob& operator--() {
		this->x -= this->y;
		this->reduce();
		return *this;
	}

	Drob& operator--(int) {
		Drob d(this->x, this->y);
		--(*this);
		return d;
	}

	bool operator==(const Drob& obj) {
		return this->getDecimal() == obj.getDecimal();
	}

	bool operator!=(const Drob& obj) {
		return !(*this == obj);
	}

	bool operator >(const Drob& obj) {
		return this->getDecimal() > obj.getDecimal();
	}

	bool operator >=(const Drob& obj) {
		return this->getDecimal() >= obj.getDecimal();
	}

	bool operator <(const Drob& obj) {
		return this->getDecimal() < obj.getDecimal();
	}

	bool operator <=(const Drob& obj) {
		return this->getDecimal() <= obj.getDecimal();
	}

	double getDecimal() const{
		return (double)this->x / this->y;
	}

	Drob& reduce() {
		int delimoe, delitel, ost = 1;
		if (this->x > this->y) {
			delimoe = this->x;
			delitel = this->y;
		}
		else {
			delimoe = this->y;
			delitel = this->x;
		}
		while (1) {
			ost = delimoe % delitel;
			if (ost == 0) break;
			delimoe = delitel;
			delitel = ost;
		}
		this->x /= delitel;
		this->y /= delitel;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Drob& d);
	friend Drob operator- (const Drob& a);
	friend istream& operator>>(istream& in, Drob& d);
};

Drob operator- (const Drob& b)
{
	Drob res(-b.getX(), b.getY());
	return res;
}

ostream& operator<<(ostream& out, const Drob& d) {
	out << d.x << "/" << d.y << " = " << (double)d.x / d.y << endl;
	return out;
}

istream& operator>>(istream& in, Drob& d) {
	cout << "Enter x\n";
	in >> d.x;
	cout << "Enter y\n";
	int q;
	in >> q;
	d.setY(q);
	return in;
}