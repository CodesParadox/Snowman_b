#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
#include <stdbool.h>
#include "snowman.hpp"
#include <stdlib.h>

using namespace std;

const array<string, 4> hats = {"_===_", " ___\n .....", "  _\n  /_\\", " ___\n (_*_)"};
const array<string, 4> noses = {",", ".", "_", " "};
const array<string, 4> Lefteye = {".", "o", "O", "-"};
const array<string, 4> Righteye = {".", "o", "O", "-"};
const array<string, 4> LeftArmTop = {" ", "\\", " ", " "};
const array<string, 4> Leftarm = {"<", " ", "/", " "};
const array<string, 4> RightArmTop = {" ", "/", " ", " "};
const array<string, 4> Rightarm = {">", " ", "\\", " "};
const array<string, 4> torsos = {" : ", "] [", "> <", "   "};
const array<string, 4> bases = {" : ", "\" \"", "___", "   "};

namespace ariel
{

	enum consitems
	{
		Hat,
		Nose,
		LeftEye,
		RightEye,
		LeftArm,
		RightArm,
		Torso,
		Base
	};

	bool checkinput(int num)
	{
		bool a = true;
		if (num < MIN || num > MAX)
		{
			a = false;
		}
		return a;
	}

	string snowman(int str)
	{
		array<int, NumberS> arr = {};
		if (checkinput(str))
		{
			int i = 0;
			int checknum;
			while (i < NumberS)
			{
				checknum = str % 10;
				if (checknum < 1 || checknum > 4)
				{
					throw invalid_argument("Invalid input");
					//close();
				}
				arr.at(7 - i) = checknum;
				str = str / 10;
				i++;
			}

			string Snostring = " " + hats.at(arr.at(Hat)) +
				        LeftArmTop.at(arr.at(LeftArm)) + "(" + Lefteye.at(arr.at(LeftEye)) + noses.at(arr.at(Nose)) + Righteye.at(arr.at(RightEye)) + ")" + RightArmTop.at(arr.at(LeftArm)) + "\n" +
				        Leftarm.at(arr.at(LeftArm)) + "(" + torsos.at(arr.at(Torso)) + ")" + RightArmTop.at(arr.at(LeftArm)) + "\n (" +
				        bases.at(arr.at(Base)) + ")";

			return Snostring;
		}
		else
		{
			throw invalid_argument("Invalid input out of range");
			//cout << "Enter new input" << endl;
		}
	}

	// int main()
	// {
	// 	//system("Color XY"); // X for the Background, Y for the text color
	// 	cout << "       ///////////***** Inventory *****\\\\\\\\\\\\\n"
	// 	     << endl;
	// 	cout << "\nID\tHats\tNoses\tEyes\tArms\tTorsos\tBases\n"
	// 	     << "[1]" << '\t' << "_===_" << '\t' << "," << '\t' << "." << '\t' << " " << '\t' << " : " << '\t' << " : "
	// 	     << "\n";

	// 	cout << "\n[2]" << '\t' << " ___ \n\t....." << '\t' << "." << '\t' << "o" << '\t' << "\\" << '\t' << "] [" << '\t' << "\" \""
	// 	     << "\n";
	// 	cout << "[3]" << '\t' << "  _\n\t /_\\" << '\t' << "_" << '\t' << "O" << '\t' << "<" << '\t' << "> <" << '\t' << "___"
	// 	     << "\n";
	// 	cout << "[4]" << '\t' << " ___\n\t(_*_)" << '\t' << " " << '\t' << "-" << '\t' << "/" << '\t' << "   " << '\t' << "   " << endl;

	// 	int s = 22222222;
	// 	snowman(s);
	// }
}