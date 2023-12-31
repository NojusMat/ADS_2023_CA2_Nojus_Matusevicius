#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2023_CA2_Nojus_Matusevicius/XMLParser.h"
#include "../ADS_2023_CA2_Nojus_Matusevicius/Tree.h"
#include "../ADS_2023_CA2_Nojus_Matusevicius/TreeIterator.h"
#include "../ADS_2023_CA2_Nojus_Matusevicius/ADS_2023_CA2_Nojus_Matusevicius.cpp"
#include <string>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ADSCA2TEST
{
	TEST_CLASS(XMLParserTest)
	{
	public:

		TEST_METHOD(TestMenu)
		{
			App app;
			app.run();
			Assert::AreEqual(2, app.choice);
		}
		TEST_METHOD(TestFileConstructor)
		{
			string filename = "myfile.xml";
			XMLParser<string> parser(filename);
			Assert::AreEqual(parser.getFilename().c_str(), filename.c_str(), L"Constructor not working");

		}
		TEST_METHOD(TestLoadFunction)
		{
			string filename = "myfile.xml";
			XMLParser<string> parser(filename);
			parser.load();
			Assert::AreEqual(parser.getFilename().c_str(), filename.c_str(), L" File does not load");
		}
		TEST_METHOD(TestInvalidFile)
		{
			string filename = "asdfghj.xml";
			XMLParser<string> parser(filename);
			bool result = parser.load();
			Assert::IsFalse(result);
		}
		TEST_METHOD(TestRoot) {
			string filename = "myfile.xml";
			ofstream file(filename);
			file << "<dir><dir></dir></dir>";
			file.close();

			XMLParser<string> parser(filename);
			parser.load();
			Assert::IsTrue(parser.hasRoot(), L"Root not found");

		}
		TEST_METHOD(TestClosingTags) {
			string filename = "myfile.xml";
			ofstream file(filename);
			file << "<dir><dir></dir></dir>";
			file.close();

			XMLParser<string> parser(filename);
			parser.load();
			Assert::IsTrue(parser.hasClosingTags(), L"Closing tags not found");

		}
		TEST_METHOD(TestOpeningTags) {
			string filename = "myfile.xml";
			XMLParser<string> parser(filename);
			parser.load();
			Assert::IsTrue(parser.hasOpeningTags(), L"Opening tags not found");

		}
		TEST_METHOD(TestNestingIsValid) {
			string filename = "myfile.xml";
			ofstream file(filename);
			file << "<dir><dir></dir></dir>";
			file.close();

			XMLParser<string> parser(filename);
			parser.load();
			Assert::IsTrue(parser.nestingIsValid(), L"Nesting is not valid");
		}

	//	TEST_METHOD(TestBuildTree) {
	//	XMLParser<string> parser("myfile.xml");
	//	parser.load();
	//	Tree<string>* root = parser.buildTree();
	//	Assert::IsNotNull(root);
	//	Assert::AreEqual(root->getData().c_str(), "dir");
	//	}

	};
}
