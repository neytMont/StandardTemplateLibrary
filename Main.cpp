#include "BigInt.h"

BigInt GoldRabbits(BigInt bigN);

using namespace std;

// here is the main function DO NOT CHANGE ANYTHING in this program.
int main()
{
	BigInt B1("123456789123456789123456789123456789");
	BigInt B2(B1);

	BigInt MAX(INT_MAX);

	cout << "B1:" << B1 << "\nB2:" << B2 << "\nMax:" << MAX;
	getchar();
	cout << "\nB1:";
	B1.print();
	cout << endl;
	getchar();

	for (BigInt i = 0; i <= 100; i++)
	{
		cout << "\ngoldRabbit of (" << i << ") = " << GoldRabbits(i) ;
	}

	getchar(); // pause after GoldRabbits

	cout << "\nThis is the value of goldRabbits(3000)\n\n";
	BigInt gR3000 = GoldRabbits(BigInt(3000));
	gR3000.print();

	getchar();


}
// you must modify this function so that it runs in a reasonable time for input of 1000
// you must use a map<BigInt, BigInt>
BigInt GoldRabbits(BigInt bigN)
{
	static map<BigInt, BigInt> fMap;
	if (bigN == 0 || bigN == 1)
	{
		return BigInt(1);
	}
	if (fMap.find(bigN) != fMap.end())
	{
		return fMap.at(bigN);
	}
	else
	{
		BigInt a = GoldRabbits(bigN - 1);
		BigInt b = GoldRabbits(bigN - 2);
		BigInt c = a + b;
		fMap[bigN] = c;
		return c;
	}
}
