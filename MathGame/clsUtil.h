
#include <iostream>
#include <string>

using namespace std;

class clsUtil
{
public:
	static void Srand()
	{
		srand((unsigned)time(NULL));
	};

	static int RandomNumber(int from, int to)
	{
		int RandomNumber = rand() % (to - from + 1) + from;

		return RandomNumber;
	};

};