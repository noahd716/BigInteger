#include <bits/stdc++.h>
using namespace std;

class BigInteger {
public:	
	// 疼硑ㄧ计 
	BigInteger (const string& str) {*this = str;}
	BigInteger (const char* str) {*this = string(str);}
	BigInteger (long long num) {*this = num;}
	BigInteger () {this->s.clear();}
	// 结ㄧ计 
	BigInteger operator= (const string& str);
	BigInteger operator= (long long num);
	
	// 籔BigInteger笲衡更ㄧ计 
	BigInteger operator+ (const BigInteger& b);
	BigInteger operator- (const BigInteger& b);
	BigInteger operator* (const BigInteger& b);
	BigInteger operator/ (const BigInteger& b);
	BigInteger operator% (const BigInteger& b);
	BigInteger operator+= (const BigInteger& b);
	BigInteger operator-= (const BigInteger& b);
	BigInteger operator*= (const BigInteger& b);
	BigInteger operator/= (const BigInteger& b);
	
	// 籔INT笲衡更ㄧ计 
	BigInteger operator+ (int b);
	BigInteger operator- (int b);
	BigInteger operator* (int b);
	BigInteger operator/ (int b);
	
	// 琘计 
	long long& operator[] (int index) {return s[index];}
	const long long& operator[] (int index) const {return s[index];} 
	
	// 块/块ㄧ计 
	friend ostream& operator<< (ostream& out, const BigInteger& b); 
	friend istream& operator>> (istream& out, const BigInteger& b);
	
	// 更ゑ耕ㄧ计 
	// 籔BigIntegerゑ耕ㄧ计 
	bool operator< (const BigInteger& b) const;
	bool operator> (const BigInteger& b) const; 
	bool operator== (const BigInteger& b) const;
	bool operator<= (const BigInteger& b) const;
	bool operator>= (const BigInteger& b) const;
	
	// 籔﹃计ゑ耕ㄧ计 
	bool operator< (const char* str) const;
	bool operator> (const char* str) const; 
	bool operator== (const char* str) const;
	bool operator<= (const char* str) const;
	bool operator>= (const char* str) const;
	
	// 计ㄧ计 
	int size() const {return s.size();}
	
	// ユ传ㄧ计
	void swap(BigInteger& b);
	
	// 耞ㄧ计
	bool empty() {return s.empty();}
	 
private:
	// BigInteger じ 
	vector<long long> s;
	static const int WIDTH = 8;
	static const int BASE = 100000000;
	vector<bool> r; 
	
	// ゑ耕ㄧ计 
	int compare (const BigInteger& b) const;
};




