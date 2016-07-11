#include "gtest/gtest.h"
#include "cWordCounter.h"

#include <string>

TEST(WordCounterTest, test_Initial)
{
	std::string line("Go do that thing that you do so well");
	cWordCounter cCounter;

	cCounter.countWords(line);
	std::unordered_map<std::string,unsigned int> mpRes = cCounter.getResult();

	EXPECT_EQ(7, mpRes.size());
	EXPECT_EQ(1, mpRes["go"]);
	EXPECT_EQ(2, mpRes["do"]);
	EXPECT_EQ(2, mpRes["that"]);
	EXPECT_EQ(1, mpRes["thing"]);
	EXPECT_EQ(1, mpRes["you"]);
	EXPECT_EQ(1, mpRes["so"]);
	EXPECT_EQ(1, mpRes["well"]);
}

TEST(WordCounterTest, test_Dante)
{
	std::string line("Segui il tuo corso et lascia dir les genti\n(Follow your road and let the people say)");
	cWordCounter cCounter;

	cCounter.countWords(line);
	std::unordered_map<std::string,unsigned int> mpRes = cCounter.getResult();

	EXPECT_EQ(17, mpRes.size());
	EXPECT_EQ(1, mpRes["segui"]);
	EXPECT_EQ(1, mpRes["il"]);
	EXPECT_EQ(1, mpRes["tuo"]);
	EXPECT_EQ(1, mpRes["corso"]);
	EXPECT_EQ(1, mpRes["et"]);
	EXPECT_EQ(1, mpRes["lascia"]);
	EXPECT_EQ(1, mpRes["dir"]);
	EXPECT_EQ(1, mpRes["les"]);
	EXPECT_EQ(1, mpRes["genti"]);
	EXPECT_EQ(1, mpRes["follow"]);
	EXPECT_EQ(1, mpRes["your"]);
	EXPECT_EQ(1, mpRes["road"]);
	EXPECT_EQ(1, mpRes["and"]);
	EXPECT_EQ(1, mpRes["let"]);
	EXPECT_EQ(1, mpRes["the"]);
	EXPECT_EQ(1, mpRes["people"]);
	EXPECT_EQ(1, mpRes["say"]);
}

TEST(WordCounterTest, test_sources)
{
	std::string line(
	"public class StringDemo"
	"{"
	    "\tstatic int i,c=0,res;"
	    "\tstatic int wordcount(String s)"
	    "\t{"
	        "\t\tchar ch[]= new char[s.length()];      //in string especially we have to mention the () after length"
	        "\t\tfor(i=0;i<s.length();i++)"
	        "\t\t{"
	            "\t\t\tch[i]= s.charAt(i);"
	            "\t\t\tif( ((i>0)&&(ch[i]!=' ')&&(ch[i-1]==' ')) || ((ch[0]!=' ')&&(i==0)) )"
	            "\t\t\tc++;"
	        "\t\t}"
	        "\t\treturn c;"
	    "\t}"
	    "\tpublic static void main (String args[])"
	    "\t{"
	        "\t\tres=StringDemo.wordcount(\"   manchester united is also known as red devil \");"
	        "\t\t//string is always passed in double quotes"
	        "\t\tSystem.out.println(\"The number of words in the String are :  \"+res);"
	    "\t}"
	"}");
	cWordCounter cCounter;

	cCounter.countWords(line);
	std::unordered_map<std::string,unsigned int> mpRes = cCounter.getResult();

	EXPECT_EQ(49, mpRes.size());
	EXPECT_EQ(1, mpRes["passed"]);
	EXPECT_EQ(1, mpRes["always"]);
	EXPECT_EQ(1, mpRes["as"]);
	EXPECT_EQ(1, mpRes["devil"]);
	EXPECT_EQ(2, mpRes["is"]);
	EXPECT_EQ(1, mpRes["red"]);
	EXPECT_EQ(1, mpRes["known"]);
	EXPECT_EQ(1, mpRes["manchester"]);
	EXPECT_EQ(1, mpRes["after"]);
	EXPECT_EQ(1, mpRes["out"]);
	EXPECT_EQ(1, mpRes["main"]);
	EXPECT_EQ(1, mpRes["also"]);
	EXPECT_EQ(1, mpRes["void"]);
	EXPECT_EQ(1, mpRes["quotes"]);
	EXPECT_EQ(1, mpRes["return"]);
	EXPECT_EQ(1, mpRes["charat"]);
	EXPECT_EQ(1, mpRes["for"]);
	EXPECT_EQ(3, mpRes["res"]);
	EXPECT_EQ(1, mpRes["united"]);
	EXPECT_EQ(1, mpRes["args"]);
	EXPECT_EQ(3, mpRes["c"]);
	EXPECT_EQ(3, mpRes["length"]);
	EXPECT_EQ(2, mpRes["stringdemo"]);
	EXPECT_EQ(1, mpRes["double"]);
	EXPECT_EQ(10, mpRes["i"]);
	EXPECT_EQ(4, mpRes["s"]);
	EXPECT_EQ(1, mpRes["words"]);
	EXPECT_EQ(3, mpRes["in"]);
	EXPECT_EQ(5, mpRes["string"]);
	EXPECT_EQ(3, mpRes["static"]);
	EXPECT_EQ(1, mpRes["class"]);
	EXPECT_EQ(1, mpRes["println"]);
	EXPECT_EQ(1, mpRes["have"]);
	EXPECT_EQ(1, mpRes["new"]);
	EXPECT_EQ(2, mpRes["char"]);
	EXPECT_EQ(1, mpRes["mention"]);
	EXPECT_EQ(2, mpRes["public"]);
	EXPECT_EQ(2, mpRes["wordcount"]);
	EXPECT_EQ(2, mpRes["int"]);
	EXPECT_EQ(1, mpRes["to"]);
	EXPECT_EQ(3, mpRes["the"]);
	EXPECT_EQ(1, mpRes["of"]);
	EXPECT_EQ(1, mpRes["we"]);
	EXPECT_EQ(1, mpRes["especially"]);
	EXPECT_EQ(1, mpRes["if"]);
	EXPECT_EQ(5, mpRes["ch"]);
	EXPECT_EQ(1, mpRes["are"]);
}


