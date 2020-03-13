//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"
using namespace std;
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}