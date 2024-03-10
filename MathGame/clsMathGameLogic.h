#pragma once

#include <iostream>
#include <string>
#include "SetSettings.h";
#include "clsSetSettings.h";
#include "clsUtil.h";

using namespace std;

class clsMathGameLogic
{
private:
	//Round Data	
	int _FirstNumber = 0;
	int _SecondNumber = 0;
	int _UserAnswer = 0;
	int _Result = 0;
	char _Operation;
	
	//Game Result Data
	int _WinTimes = 0;
	int _LoseTimes = 0;
	
	int _GenerateNumber()
	{
		clsSetSettings::enDifficulty Def = clsSetSettings::enDifficulty(GameSettings.Deff);

		if (Def == clsSetSettings::eMixDiff)
			Def = clsSetSettings::enDifficulty(clsUtil::RandomNumber(1, 3));

		switch (Def)
		{
		case clsSetSettings::enDifficulty::eEasy:
		{
			return clsUtil::RandomNumber(1, 10);
		}
		case clsSetSettings::enDifficulty::eMedium:
		{
			return clsUtil::RandomNumber(10, 50);
		}
		case clsSetSettings::enDifficulty::eHrad:
		{
			return clsUtil::RandomNumber(50, 150);
		}
		}
	}

	char _GenerateOperation()
	{
		clsSetSettings::enOperation Operation = clsSetSettings::enOperation(GameSettings.Operation);

		if (Operation == clsSetSettings::eMixOperation)
			Operation = clsSetSettings::enOperation(clsUtil::RandomNumber(1, 4));

		switch (Operation)
		{
		case clsSetSettings::enOperation::ePlus:
		{
			return '+';
		}
		case clsSetSettings::enOperation::eSubtract:
		{
			return '-';
		}
		case clsSetSettings::enOperation::eMultipli:
		{
			return '*';
		}
		case clsSetSettings::enOperation::eDivision:
		{
			return '/';
		}
		}
	}

	int _GetResult()
	{
		switch (_Operation)
		{
		case '+':
			return _FirstNumber + _SecondNumber;
		case '-':
			return _FirstNumber - _SecondNumber;
		case '*':
			return _FirstNumber * _SecondNumber;
		case '/':
			return _FirstNumber / _SecondNumber;
		}
	}

public:
	//Read Only
	int FirstNumber()
	{
		return _FirstNumber;
	}
	
	int SecondNumber()
	{
		return _SecondNumber;
	}
	
	char Operation()
	{
		return _Operation;
	}

	//Property Get
	int GetUserAnswer()
	{
		return _UserAnswer;
	}

	int GetWinTimes()
	{
		return _WinTimes;
	}

	int GetLoseTimes()
	{
		return _LoseTimes;
	}

	//Property Set
	void SetUserAnswer(int UserAnswer)
	{
		_UserAnswer = UserAnswer;
	}

	void SetWinTimes(int WinTimes)
	{
		_WinTimes = WinTimes;
	}

	void SetLoseTimes(int LoseTimes)
	{
		_LoseTimes = LoseTimes;
	}

	__declspec(property(get = GetUserAnswer, put = SetUserAnswer )) int UserAnswer;
	__declspec(property(get = GetWinTimes,   put = SetWinTimes   )) int WinTimes;
	__declspec(property(get = GetLoseTimes,  put = SetLoseTimes  )) int LoseTimes;

	int GenerateFirstNumber()
	{
		_FirstNumber = _GenerateNumber();
		return _FirstNumber;
	}
	
	int GenerateSecondNumber()
	{
		_SecondNumber = _GenerateNumber();

		return _SecondNumber;
	}

	char GenerateOperation()
	{
		_Operation = _GenerateOperation();

		return _Operation;
	}

	int CalculateResult()
	{
		_Result = _GetResult();

		return _Result;
	}

	bool CheckUserAnswer()
	{
		return (_Result == _UserAnswer);
	}

	string GetRoundResult()
	{
		if (CheckUserAnswer())
		{
			system("color 2f");
			_WinTimes++;
			return "Right Answer";
		}
		else
		{
			system("color 4f");
			_LoseTimes++;
			return "Wrong Answer";
		}
	}

	string GetFinalResult()
	{
		if(_WinTimes == _LoseTimes)
			return "Tie";

		if (_WinTimes > _LoseTimes)
		{
			system("color 2f");
			return "Win";
		}
		else
		{
			system("color 4f");
			return "Lose";
		}
	}
};
