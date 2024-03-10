#pragma once

#include <iostream>

using namespace std;

class clsHeaderScreen
{
protected:
	static void PrintHeader(string Title)
	{
		cout << "------------------------------------" << endl << endl;
		cout << "\t  " << Title << endl << endl;
		cout << "------------------------------------" << endl << endl;
	}
};

