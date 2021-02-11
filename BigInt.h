#pragma once
#ifndef BigInt_h
#define BigInt_h

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

class BigInt
{
private:
	vector<int> storage;
	// I needed these next 2 functions but you may or may not need them depending how you implement your class
	void stripLeadingZero(BigInt&); // you need to make sure you don't have a number like this: '0123";
public:
	BigInt();
	BigInt(int);
	BigInt(string);
	BigInt operator++(int);
	bool operator<=(BigInt);
	bool operator==(int);
	bool operator==(BigInt);
	BigInt operator-(BigInt);
	BigInt operator-(int);
	BigInt operator+(BigInt);
	bool operator<(const BigInt&) const;  // this is required for the map
	friend ostream& operator<<(ostream&, const BigInt&);
	void print();
};

#endif 