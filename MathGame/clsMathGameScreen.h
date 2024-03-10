#pragma once

#include <iostream>
#include <string>
#include "clsScreenHeader.h";
#include "SetSettings.h";
#include "clsMathGameLogic.h";
#include "clsUtil.h";

using namespace std;

class clsMathGameScreen : protected clsHeaderScreen
{
private:
	static void _PrintEquation(clsMathGameLogic &MathLogic)
	{
		cout << MathLogic.GenerateFirstNumber()          << endl;
		cout << "     " << MathLogic.GenerateOperation() << endl;
		cout << MathLogic.GenerateSecondNumber()         << endl;

		cout << endl << "---------------------" << endl << endl;
	}

	static int _ReadUserAnswer()
	{
		int UserAnswer = 0;
		cin >> UserAnswer;
		return UserAnswer;
	}

	static void _PrintRoundResult(clsMathGameLogic &MathLogic)
	{
		cout << endl << endl << "---------------------------" << endl << endl;
		cout << "Your Answer    = " << MathLogic.UserAnswer        << endl;
		cout << "Correct Answer = " << MathLogic.CalculateResult() << endl;
		cout << "Round Result   = " << MathLogic.GetRoundResult()  << endl;
		cout << endl << "---------------------------" << endl << endl;
	}

	static void _StartGame(clsMathGameLogic &MathLogic)
	{
		system("cls");

		PrintHeader("Start Game !");

		for (int i = 1; i <= GameSettings.Rounds; i++)
		{
			_PrintEquation(MathLogic);

			MathLogic.UserAnswer = _ReadUserAnswer();

			_PrintRoundResult(MathLogic);
		}
	}

	static void _EndScreen(clsMathGameLogic &MathLogic)
	{
		system("cls");
		system("color 0f");

		PrintHeader("Final Result");

		cout << "Win Times    = " << MathLogic.WinTimes 		<< endl << endl;
		cout << "Lose Times   = " << MathLogic.LoseTimes		<< endl << endl;
		cout << "Final Reault = " << MathLogic.GetFinalResult() << endl << endl;

		MathLogic.WinTimes  = 0;
		MathLogic.LoseTimes = 0;
	}

	static void _GoToEndScreen(clsMathGameLogic &MathLogic)
	{
		cout << "\nPress Any Key To See Game Results...";
		system("pause>0");
		_EndScreen(MathLogic);
	}
public:
	static void StartGame()
	{
		clsUtil::Srand();
		clsMathGameLogic MathLogic;
		char OneMore = 'y';

		do
		{
			system("cls");
			system("color 0f");

			GameSettings.SetGameSettings();

			_StartGame(MathLogic);

			_GoToEndScreen(MathLogic);

			cout << "\n\nDo You Want To Play Again Y/N ? ";
			cin >> OneMore;

		} while(OneMore == 'y' || OneMore == 'Y');
	}

};