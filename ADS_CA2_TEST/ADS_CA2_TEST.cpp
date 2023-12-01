#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2023_CA2_Nojus_Matusevicius/XMLParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ADSCA2TEST
{
	TEST_CLASS(ADSCA2TEST)
	{
	public:
		
		TEST_METHOD(TestRootTrue)
		{
			string xmlRoot = "<root></root>";
			XMLParser parser;
			Assert::IsTrue(parser.isRoot(xmlRoot));	

		}

	};
}
