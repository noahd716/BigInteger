#include <bits/stdc++.h>
using namespace std;

class BigInteger {
public:	
	// ÌÛ³y¨ç¼Æ 
	BigInteger (const string& str) {*this = str;}
	BigInteger (const char* str) {*this = string(str);}
	BigInteger (long long num) {*this = num;}
	BigInteger () {*this = 0;}
	// ½á­È¨ç¼Æ 
	BigInteger operator= (const string& str);
	BigInteger operator= (long long num);
	
	// »PBigInteger¹Bºâªº­«¸ü¨ç¼Æ 
	BigInteger operator+ (const BigInteger& b);
	BigInteger operator- (const BigInteger& b);
	BigInteger operator* (const BigInteger& b);
	BigInteger operator/ (const BigInteger& b);
	
	// »PINT¹Bºâªº­«¸ü¨ç¼Æ 
	BigInteger operator+ (int num);
	BigInteger operator- (int num);
	BigInteger operator* (int num);
	BigInteger operator/ (int num);
	
	// ªð¦^¬Y¤@¦ì¼Æªº­È 
	int& operator[] (int index) {return s[index];}
	const int& operator[] (int index) const {return s[index];} 
	
	// ¿é¥X/¿é¤J¨ç¼Æ 
	friend ostream& operator<< (ostream& out, const BigInteger& b); 
	friend istream& operator>> (istream& out, const BigInteger& b);
	
	// ­«¸ü¤ñ¸û¤j¤p¨ç¼Æ 
	// »PBigInteger¤ñ¸û¤j¤p¨ç¼Æ 
	bool operator< (const BigInteger& b) const;
	bool operator> (const BigInteger& b) const; 
	bool operator== (const BigInteger& b) const;
	bool operator<= (const BigInteger& b) const;
	bool operator>= (const BigInteger& b) const;
	
	// »P¦r¦ê«¬¼Æ¦r¤ñ¸û¤j¤p¨ç¼Æ 
	bool operator< (const char* str) const;
	bool operator> (const char* str) const; 
	bool operator== (const char* str) const;
	bool operator<= (const char* str) const;
	bool operator>= (const char* str) const;
	
	// ¼Æ­Èªø«×¨ç¼Æ 
	int size() const {return s.size();}
	
	// ¥æ´«¨ç¼Æ
	void swap(BigInteger& b); 
	 
private:
	// BigInteger ¤¸¯À 
	vector<int> s;
	static const int WIDTH = 8;
	static const int BASE = 100000000;
	
	// ¤ñ¸û¤j¤p¨ç¼Æ 
	int compare (const BigInteger& b) const;
};

BigInteger BigInteger::operator= (const string& str) {
	string copy(str);
	s.clear();
	int start, end, x, len = (str.length() - 1) / WIDTH + 1;
	for (int i = 0; i < len; i++) {
		end = str.length() - i * WIDTH;
		start = max(0, end - WIDTH);
		sscanf (copy.substr(start, end-start).c_str(), "%d", &x);
		s.push_back(x);
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
	int i, g, x;
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
	int i, g, x;
	
	if (*this == b) {
		c.s.push_back(0);
	} else {
		if (*this < b) this->swap(b);
		for (i = 0, g = 0; ; i++) {
			cout << i << " " << g << endl;
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
	for (int i = b.s.size()-2; i >= 0; i--) {
		out << b.s[i];
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
