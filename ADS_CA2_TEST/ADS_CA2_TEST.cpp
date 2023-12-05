#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2023_CA2_Nojus_Matusevicius/XMLParser.h"
#include <string>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ADSCA2TEST
{
	TEST_CLASS(XMLParserTest)
	{
	public:
		TEST_METHOD(TestFileConstructor)
		{
			string filename = "myfile.xml";
			XMLParser<string> parser(filename);
			Assert::AreEqual(parser.getFilename().c_str(), filename.c_str());

		}
		TEST_METHOD(TestLoadFunction)
		{
			string filename = "myfile.xml";
			XMLParser<string> parser(filename);
			parser.load();
			Assert::AreEqual(parser.getFilename().c_str(), filename.c_str());
		}
		TEST_METHOD(TestInvalidFile)
		{
			string filename = "asdfghj.xml";
			XMLParser<string> parser(filename);
			bool result = parser.load();
			Assert::IsFalse(result);
		}
	}
	;
}
