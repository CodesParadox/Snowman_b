#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

//Checking path:
//hat -> nose -> left eye -> right eye -> left arm -> right arm -> torso -> base
string nospaces(string input)
{
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code")
{

	//check hat
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(21114411)) == nospaces("___\n.....\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(31114411)) == nospaces("_\n/_\\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(41114411)) == nospaces("__\n(_*_)\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(31111111)) == nospaces("  _  \n  /_\\ \n (.,.) \n<( : )>\n ( : ) "));
	CHECK(nospaces(snowman(41111111)) == nospaces(" ___ \n (_*_)\n (.,.) \n<( : )>\n ( : ) "));

	//check nose
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
	CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(..)\n( : )\n( : )"));

	//check left eye
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(12214411)) == nospaces("_===_\n(o..)\n( : )\n( : )"));
	CHECK(nospaces(snowman(13314411)) == nospaces("_===_\n(O_.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(14414411)) == nospaces("_===_\n(-.)\n( : )\n( : )"));

	//check right eye
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(12224411)) == nospaces("_===_\n(o.o)\n( : )\n( : )"));
	CHECK(nospaces(snowman(13334411)) == nospaces("_===_\n(O_O)\n( : )\n( : )"));
	CHECK(nospaces(snowman(14444411)) == nospaces("_===_\n(--)\n( : )\n( : )"));

	//check left arm
	CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
	CHECK(nospaces(snowman(13333411)) == nospaces("_===_\n(O_O)\n/( : )\n( : )"));
	CHECK(nospaces(snowman(14444411)) == nospaces("_===_\n(--)\n( : )\n( : )"));

	//check right arm
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(12224111)) == nospaces("_===_\n(o.o)\n( : )>\n( : )"));
	CHECK(nospaces(snowman(13334211)) == nospaces("_===_\n(O_O)/\n( : )\n( : )"));

	//change torso
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(12224421)) == nospaces("_===_\n(o.o)\n( ][ )\n( : )"));
	CHECK(nospaces(snowman(13334431)) == nospaces("_===_\n(O_O)\n( __ )\n( : )"));
	CHECK(nospaces(snowman(14444441)) == nospaces("_===_\n(--)\n(   )\n( : )"));

	//check base
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(12224422)) == nospaces("_===_\n(o.o)\n( ][ )\n( "
					  " )"));
	CHECK(nospaces(snowman(13334433)) == nospaces("_===_\n(O_O)\n( __ )\n( __ )"));
	CHECK(nospaces(snowman(14444444)) == nospaces("_===_\n(--)\n(   )\n(   )"));
}

////TEST_CASE("Bad snowman code") {

TEST_CASE("Small numbers or Big numbers input")
{
	CHECK_THROWS(snowman(1));
	CHECK_THROWS(snowman(12));
	CHECK_THROWS(snowman(123));
	CHECK_THROWS(snowman(12345));
	CHECK_THROWS(snowman(123456));
	CHECK_THROWS(snowman(112345));
	CHECK_THROWS(snowman(11234567));
	CHECK_THROWS(snowman(4));
	CHECK_THROWS(snowman(1134534));
	CHECK_THROWS(snowman(123456789));
}

TEST_CASE("Invalid characters")
{
	CHECK_THROWS(snowman(01114411));
	CHECK_THROWS(snowman(15114411));
	CHECK_THROWS(snowman(11614411));
	CHECK_THROWS(snowman(11174411));
	CHECK_THROWS(snowman(11118411));
	CHECK_THROWS(snowman(11114911));
	CHECK_THROWS(snowman(11114401));
	CHECK_THROWS(snowman(11114417));
}

TEST_CASE("negtive numbers")
{
	CHECK_THROWS(snowman(-164556));
	CHECK_THROWS(snowman(-1464646415));
	CHECK_THROWS(snowman(-2777715));
	CHECK_THROWS(snowman(-16547115));
	CHECK_THROWS(snowman(-53311115));
	CHECK_THROWS(snowman(-55554115));
	CHECK_THROWS(snowman(-11614396));
	CHECK_THROWS(snowman(-12745656));
}
