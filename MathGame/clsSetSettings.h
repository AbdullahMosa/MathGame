#pragma once

#include <iostream>
#include <string>
#include "clsScreenHeader.h";

using namespace std;

class clsSetSettings : public clsHeaderScreen
{
private:
	int _Rounds = 0;
	int _Deff;
	int _Operation;

public:
	//Property Get
	int GetRounds()
	{
		return _Rounds;
	}
	
	int GetDeff()
	{
		return _Deff;
	}
	
	int GetOperation()
	{
		return _Operation;
	}

	//Property Set
	void SetRounds(int Rounds)
	{
		_Rounds = Rounds;
	}

	void SetDeff(int Deff)
	{
		_Deff = Deff;
	}

	void SetOperation(int Operation)
	{
		_Operation = Operation;
	}

	__declspec(property(get = GetRounds, put = SetRounds)) int Rounds;
	__declspec(property(get = GetDeff, put = SetDeff)) int Deff;
	__declspec(property(get = GetOperation, put = SetOperation)) int Operation;

	enum enDifficulty
	{
		eEasy = 1,
		eMedium = 2,
		eHrad = 3,
		eMixDiff = 4
	};

	enum enOperation
	{
		ePlus = 1,
		eSubtract = 2,
		eMultipli = 3,
		eDivision = 4,
		eMixOperation = 5,
	};

	void SetGameSettings()
	{
		PrintHeader("Game Settings");

		cout << "Please Enter The Rounds That You Want : ";
		cin >> _Rounds;

		cout << "\nAnd The Deff [1]: Easy, [2]: Med, [3]: Hard, [4]: Mix ? ";
		cin >> _Deff;

		cout << "\nAnd The Operation [1]: +, [2]: -, [3]: *, [4]: /, [5]: Mix ? ";
		cin >> _Operation;
	}
};

