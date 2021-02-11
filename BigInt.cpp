
#include "BigInt.h"


BigInt::BigInt()
{
	storage.push_back(0);
}

void BigInt::stripLeadingZero(BigInt& bigN)
{
	while (bigN.storage.front() == 0 && bigN.storage.size() > 1)
	{
		bigN.storage.pop_back();
	}
}

BigInt::BigInt(int n)
{
	if (n == 0)
	{
		storage.push_back(0);
	}
	while (n != 0)
	{
		storage.push_back(n % 10);
		n = n / 10;
	}
}

BigInt::BigInt(string bigS)
{
	
	for (int i = bigS.size() - 1; i >= 0; i--)
	{
		storage.push_back(bigS.at(i) - '0');
	}
	
}

BigInt BigInt::operator++(int dumy)
{
	*this = *this + BigInt(1);
	return *this;
}

bool BigInt::operator<(const BigInt& bigN) const
{
	if (storage.size() < bigN.storage.size())
	{
		return true;
	}
	else if (storage.size() > bigN.storage.size())
	{
		return false;
	}
	else
	{
		for (int i = storage.size() - 1; i > 0; i--)
		{
			if (storage[i] < bigN.storage[i])
			{
				return true;
			}
			else if (storage[i] > bigN.storage[i])
			{
				return false;
			}
		}
		return storage < bigN.storage;
	}
}

bool BigInt::operator<=(BigInt bigN)
{
	if (*this == bigN || *this < bigN)
	{
		return true;
	}
	return false;
}

bool BigInt::operator==(BigInt bigN)
{
	if (storage.size() == bigN.storage.size())
	{
		for (int i = storage.size() - 1; i >= 0 && bigN.storage[i] == storage[i]; i--)
		{
			if (i == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool BigInt::operator==(int n)
{
	return *this == BigInt(n);
}

BigInt BigInt::operator-(int n)
{
	return *this - BigInt(n);
}

BigInt BigInt::operator-(BigInt bigN)
{
	BigInt temp;
	BigInt thisTemp(*this);
	temp.storage.pop_back();
	vector<int>::iterator thisIt = thisTemp.storage.begin();
	vector<int>::iterator bigNIt = bigN.storage.begin();
	int result;
	int borrowLoc = 0; // Borrow helper

	while (thisIt != thisTemp.storage.end() || bigNIt != bigN.storage.end())
	{
		if (bigNIt == bigN.storage.end())
		{
			result = *thisIt;
			temp.storage.push_back(result);
			thisIt++;
		}
		else
		{
			// borrow
			if (*thisIt - *bigNIt < 0)
			{
				*thisIt = *thisIt + 10; // Borrowed
				int finder = *thisIt;
				borrowLoc++;
				while (thisTemp.storage[borrowLoc] == 0) // Until reaches a value that can be borrowed from
				{
					borrowLoc++;
				}
				thisTemp.storage[borrowLoc] -= 1; // Borrows
				borrowLoc--;
				while (thisTemp.storage[borrowLoc] != finder) // If zero's between "borrower" and "borrowee",
				{											  // adds and borrows until the original number is found
					thisTemp.storage[borrowLoc] += 9;
					borrowLoc--;
				}
			}
			result = *thisIt - *bigNIt;
			temp.storage.push_back(result);
			thisIt++;
			bigNIt++;
		}
		borrowLoc++;
	}
	stripLeadingZero(temp);
	return temp;
}

BigInt BigInt::operator+(BigInt bigN)
{
	BigInt temp;
	temp.storage.pop_back();
	vector<int>::iterator thisIter = storage.begin();
	vector<int>::iterator bigNIter = bigN.storage.begin();
	int result;
	int carry = 0;

	while (thisIter != storage.end() || bigNIter != bigN.storage.end())
	{
		if (thisIter == storage.end())
		{
			result = *bigNIter + carry;
			if (result > 9)
			{
				carry = result / 10;
				result = result % 10;
			}
			else
			{
				carry = 0;
			}
			temp.storage.push_back(result);
			bigNIter++;
		}
		else if (bigNIter == bigN.storage.end())
		{
			result = *thisIter + carry;
			if (result > 9)
			{
				carry = result / 10;
				result = result % 10;
			}
			else
			{
				carry = 0;
			}
			temp.storage.push_back(result);
			thisIter++;
		}
		else
		{
			result = *thisIter + *bigNIter + carry;
			if (result > 9)
			{
				carry = result / 10;
				result = result % 10;
			}
			else
			{
				carry = 0;
			}
			temp.storage.push_back(result);
			thisIter++;
			bigNIter++;
		}
	}
	if (carry != 0)
	{
		temp.storage.push_back(carry);
	}
	return temp;
}

ostream& operator<<(ostream& out, const BigInt& bigN)
{
	int vecSize = bigN.storage.size();

	if (vecSize <= 12)  
	{
		for (int i = 0; i < vecSize; ++i)
		{
			out << bigN.storage[i];
		}
	}
	else 
	{
		out << bigN.storage[0] << ".";
		for (int i = 1; i < 12; ++i)
		{
			out << bigN.storage[i];
		}
		out << "e" << (vecSize - 1);
	}
	return out;

}
void BigInt::print() {
	for (int index = 0; index < storage.size(); index++) {
		cout << storage[index];
	}
	cout << endl;
}