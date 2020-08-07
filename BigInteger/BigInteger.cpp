#include "BigInteger.h"

BigInteger BigInteger::operator= (const string& str) {
	string copy(str);
	s.clear();
	int start, end, len = (str.length() - 1) / WIDTH + 1, i, j;
	int x;
	for (i = 0; i < len; i++) {
		end = str.length() - i * WIDTH;
		start = max(0, end - WIDTH);
		// 如果 str 中出現開頭是零或連續兩個以上的零 的話
		// ...
		sscanf (copy.substr(start, end-start).c_str(), "%d", &x);
		s.push_back((long long)x);
	}
	return *this;
}

BigInteger BigInteger::operator= (long long num) {
	s.clear();
	do {
		s.push_back(num % BASE);
		num /= BASE;
	}while (num > 0);
	return * this;
}

BigInteger BigInteger::operator+ (const BigInteger& b) {
	BigInteger c;
	c.s.clear();
	int i;
	long long x, g;
	
	for (i = 0, g = 0; ; i++) {
		if (g == 0 && i >= b.size() && i >= size()) break;
		x = g;
		if (i < size()) x += (*this)[i];
		if (i < b.size()) x += b[i];
		c.s.push_back(x % BASE);
		g = x / BASE; 
	}
	return c;
}

BigInteger BigInteger::operator- (const BigInteger& rhs) {
	BigInteger c;
	BigInteger b(rhs);
	c.s.clear();
	int i;
	long long g, x;
	
	if (*this == b) {
		c.s.push_back(0);
	} else {
		if (*this < b) this->swap(b);
		for (i = 0, g = 0; ; i++) {
			if (g == 0 && i >= size() && i >= b.size()) break;
			x = 0;
			if (i < size()) x = (*this)[i] - g;
			if (i < b.size()) x -= b[i];
			g = 0;
			while (x < 0) {
				g += 1;
				x += BASE;
			}
			c.s.push_back(x);
		}
	}
	
	return c;	
}

BigInteger BigInteger::operator* (const BigInteger& b) {
	BigInteger c;
	int i, j;
	long long x = 0, g;
	for (i = 0; i < size(); i++) {
		
		BigInteger d;
		
		for (j = 0; j < i; j++) d.s.push_back(0); 
		
		g = 0;
		
		for (j = 0; j < b.size(); j++) {
			x = (*this)[i] * b[j] + g;
			g = x / BASE;
			d.s.push_back(x % BASE);
		}
		
		while (g > 0) {
			d.s.push_back(g % BASE);
			g /= BASE;
		}
		
		c += d;		
	}
	return c;
}

BigInteger BigInteger::operator+= (const BigInteger& b) {
	*this = *this + b; return *this;
}

BigInteger BigInteger::operator-= (const BigInteger& b) {
	*this = *this - b; return *this;
}

BigInteger BigInteger::operator*= (const BigInteger& b) {
	*this = *this * b; return *this;
}

BigInteger BigInteger::operator+ (int b) {
	return (*this + BigInteger((long long)b));
}

BigInteger BigInteger::operator* (int b) {
	BigInteger c;
	int i, j, g, len = i / BASE;
	long long x;
	for (i = 0, g = 0; ; i++) {
		x = 1;
		if (g == 0 && i >= size()) break;
		if (i < size()) x = (*this)[i] * b + g;
		g = x / BASE;
		c.s.push_back(x % BASE); 
	}
	return c;
}

bool BigInteger::operator< (const BigInteger& b) const {
	if (this->compare(b) < 0) {
		return true;
	} else {
		return false;
	}	
}

bool BigInteger::operator> (const BigInteger& b) const {
	if (this->compare(b) > 0) {
		return true;
	} else {
		return false;
	}
}

bool BigInteger::operator== (const BigInteger& b) const {
	if (this->compare(b) == 0) {
		return true;
	} else {
		return false;
	}
}

bool BigInteger::operator<= (const BigInteger& b) const {
	if (*this < b || *this == b) {
		return true;
	} else {
		return false;
	}
}

bool BigInteger::operator>= (const BigInteger& b) const {
	if (*this > b || *this == b) {
		return true;
	} else {
		return false;
	}
}

bool BigInteger::operator< (const char* str) const {
	BigInteger b(str);
	return (*this < b);
}

bool BigInteger::operator> (const char* str) const {
	BigInteger b(str);
	return (*this > b);
}

bool BigInteger::operator== (const char* str) const {
	BigInteger b(str);
	return (*this == b);
}

bool BigInteger::operator<= (const char* str) const {
	BigInteger b(str);
	return (*this <= b);
} 

bool BigInteger::operator>= (const char* str) const {
	BigInteger b(str);
	return (*this >= b);
}

void BigInteger::swap(BigInteger& b) {
	std::swap(this->s, b.s);
}	 

ostream& operator<< (ostream& out, const BigInteger& b) {
	out << b.s.back();
	for (int i = b.size()-2; i >= 0; i--) {
		char buf[20];
		sprintf (buf, "%08d", b[i]);
		out << buf;
	}
	return out;
}

istream& operator>> (istream& in, BigInteger& b) {
	string str;
	if (!(in >> str)) return in;
	b = str;
	return in;
}

int BigInteger::compare (const BigInteger& b) const {
	if (size() > b.size()) {
		return 1; 
	} else if (b.size() > size()) {
		return -1;
	} else {
		int i = size()-1;
		do {
			if ((*this)[i] > b[i]) return 1;
			else if ((*this)[i] < b[i]) return -1;
			i--;
		} while (i > 0);
		return 0;
	}	
}
