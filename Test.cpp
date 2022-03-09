#include "doctest.h"
#include "mat.hpp"
using namespace ariel;
#include <iterator>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}



TEST_CASE("good input"){
  CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
    CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));
    CHECK(nospaces(mat(1, 5, '@', '-')) == nospaces("@\n""@\n""@\n""@\n""@\n""@"));
    CHECK(nospaces(mat(3, 1, '@', '-')) == nospaces("@@@"));
    CHECK(nospaces(mat(5, 3, '#', '^')) == nospaces("#####\n""#^^^#\n""#####"));
    CHECK(nospaces(mat(3, 7, ',', '.')) == nospaces(",,,\n"",.,\n"",.,\n"",.,\n"",.,\n"",.,\n"",,,"));
    CHECK(nospaces(mat(5, 5, '?', '!')) == nospaces("?????\n""?!!!?\n""?!?!?\n""?!!!?\n""?????"));
    CHECK(nospaces(mat(11, 3, '*', '$')) == nospaces("***********\n""*$$$$$$$$$*\n""***********"));
    CHECK(nospaces(mat(7, 5, '&', '%')) == nospaces("&&&&&&&\n""&%%%%%&\n""&%&&&%&\n""&%%%%%&\n""&&&&&&&"));
    CHECK(nospaces(mat(3, 3, '@', '!')) == nospaces("@@@\n""@!@\n""@@@"));
    CHECK(nospaces(mat(9, 1, '^', '*')) == nospaces("^^^^^^^^^"));
    CHECK(nospaces(mat(7, 7, '$', '-')) == nospaces("$$$$$$$\n""$-----$\n""$-$$$-$\n""$-$-$-$\n""$-$$$-$\n""$-----$\n""$$$$$$$"));
    CHECK(nospaces(mat(7, 9, '+', '-')) == nospaces("+++++++\n""+-----+\n""+-+++-+\n""+-+-+-+\n""+-+-+-+\n""+-+-+-+\n""+-+++-+\n""+-----+\n""+++++++"));
    CHECK(nospaces(mat(3, 11, '(', ')')) == nospaces("(((\n""()(\n""()(\n""()(\n""()(\n""()(\n""()(\n""()(\n""()(\n""()(\n""((("));
    CHECK(nospaces(mat(13, 7, '[', ']')) == nospaces("[[[[[[[[[[[[[\n""[]]]]]]]]]]][\n""[][[[[[[[[[][\n""[][]]]]]]][][\n""[][[[[[[[[][\n""[]]]]]]]]]]][\n""[[[[[[[[[[[[["));
    CHECK(nospaces(mat(15, 1, '{', '*')) == nospaces("{{{{{{{{{{{{{{{"));
    CHECK(nospaces(mat(11, 3, '%', '@')) == nospaces("%%%%%%%%%%%\n""%@@@@@@@@@%\n""%%%%%%%%%%%"));
    CHECK(nospaces(mat(1, 1, '&', '*')) == nospaces("&"));
    CHECK(nospaces(mat(1, 5, '%', '?')) == nospaces("%\n""%\n""%\n""%\n""%"));
    CHECK(nospaces(mat(5, 1, '?', '-')) == nospaces("?????"));
    CHECK(nospaces(mat(9, 3, '!', '+')) == nospaces("!!!!!!!!!\n""!+++++++!\n""!!!!!!!!!"));
}

TEST_CASE("bad input"){
     CHECK_THROWS(mat(12, 3, '!', '+'));
     CHECK_THROWS(mat(0, 1, '!', '+'));
     CHECK_THROWS(mat(10, 10, '!', '+'));
     CHECK_THROWS(mat(12, 13, '!', '+'));
     CHECK_THROWS(mat(9, 3, '!', '!'));
     CHECK_THROWS(mat(7, 7, '7', '@'));
     CHECK_THROWS(mat(24, 2, '-', '+'));
     CHECK_THROWS(mat(-3, 11, '?', '-'));
     CHECK_THROWS(mat(0, 0, '@', '^'));
     CHECK_THROWS(mat(113, 5, '+', '+'));
     CHECK_THROWS(mat(5, 4, '-', '+'));
     CHECK_THROWS(mat(11, 7, 'd', 'f'));
     CHECK_THROWS(mat(8, 6, '#', '*'));
     CHECK_THROWS(mat(2, 4, '[', ')'));
     CHECK_THROWS(mat(1, 14, '{', '*'));
     CHECK_THROWS(mat(5, 9, ' ', '*'));
     CHECK_THROWS(mat(1, 3, '!', ' '));
     CHECK_THROWS(mat(5, 1, '*', '6'));
     CHECK_THROWS(mat(1, 7, '&', '9'));
     CHECK_THROWS(mat(11, 1, '!', ' '));
     
}

TEST_CASE("big input"){
  CHECK(nospaces(mat(21, 15, '+', '@')) == nospaces("+++++++++++++++++++++\n"
                                                    "+@@@@@@@@@@@@@@@@@@@+\n"
                                                    "+@+++++++++++++++++@+\n"
                                                    "+@+@@@@@@@@@@@@@@@+@+\n"
                                                    "+@+@+++++++++++++@+@+\n"
                                                    "+@+@+@@@@@@@@@@@+@+@+\n"
                                                    "+@+@+@+++++++++@+@+@+\n"
                                                    "+@+@+@+@@@@@@@+@+@+@+\n"
                                                    "+@+@+@+++++++++@+@+@+\n"
                                                    "+@+@+@@@@@@@@@@@+@+@+\n"
                                                    "+@+@+++++++++++++@+@+\n"
                                                    "+@+@@@@@@@@@@@@@@@+@+\n"
                                                    "+@+++++++++++++++++@+\n"
                                                    "+@@@@@@@@@@@@@@@@@@@+\n"
                                                    "+++++++++++++++++++++"));   
}
