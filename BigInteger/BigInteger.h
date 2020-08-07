#include <bits/stdc++.h>
using namespace std;

class BigInteger {
public:	
	// �۳y��� 
	BigInteger (const string& str) {*this = str;}
	BigInteger (const char* str) {*this = string(str);}
	BigInteger (long long num) {*this = num;}
	BigInteger () {this->s.clear();}
	// ��Ȩ�� 
	BigInteger operator= (const string& str);
	BigInteger operator= (long long num);
	
	// �PBigInteger�B�⪺������� 
	BigInteger operator+ (const BigInteger& b);
	BigInteger operator- (const BigInteger& b);
	BigInteger operator* (const BigInteger& b);
	BigInteger operator/ (const BigInteger& b);
	BigInteger operator% (const BigInteger& b);
	BigInteger operator+= (const BigInteger& b);
	BigInteger operator-= (const BigInteger& b);
	BigInteger operator*= (const BigInteger& b);
	BigInteger operator/= (const BigInteger& b);
	
	// �PINT�B�⪺������� 
	BigInteger operator+ (int b);
	BigInteger operator- (int b);
	BigInteger operator* (int b);
	BigInteger operator/ (int b);
	
	// ��^�Y�@��ƪ��� 
	long long& operator[] (int index) {return s[index];}
	const long long& operator[] (int index) const {return s[index];} 
	
	// ��X/��J��� 
	friend ostream& operator<< (ostream& out, const BigInteger& b); 
	friend istream& operator>> (istream& out, const BigInteger& b);
	
	// ��������j�p��� 
	// �PBigInteger����j�p��� 
	bool operator< (const BigInteger& b) const;
	bool operator> (const BigInteger& b) const; 
	bool operator== (const BigInteger& b) const;
	bool operator<= (const BigInteger& b) const;
	bool operator>= (const BigInteger& b) const;
	
	// �P�r�ꫬ�Ʀr����j�p��� 
	bool operator< (const char* str) const;
	bool operator> (const char* str) const; 
	bool operator== (const char* str) const;
	bool operator<= (const char* str) const;
	bool operator>= (const char* str) const;
	
	// �ƭȪ��ר�� 
	int size() const {return s.size();}
	
	// �洫���
	void swap(BigInteger& b);
	
	// �P�_�Ũ��
	bool empty() {return s.empty();}
	 
private:
	// BigInteger ���� 
	vector<long long> s;
	static const int WIDTH = 8;
	static const int BASE = 100000000;
	vector<bool> r; 
	
	// ����j�p��� 
	int compare (const BigInteger& b) const;
};




