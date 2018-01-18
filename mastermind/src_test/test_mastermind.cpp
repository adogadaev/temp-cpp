#include "gtest/gtest.h"
#include "GameBoard.h"

TEST(MastermindTest, test_game)
{
	CGameBoard cBoard(4, 8);
	cBoard.setSecret("gcrm");

	cBoard.processCurCode("yycc");
	EXPECT_EQ("o___", cBoard.getKeyPrintable());
	EXPECT_EQ(false, cBoard.chckKey());

	cBoard.processCurCode("mrry");
	EXPECT_EQ("vo__", cBoard.getKeyPrintable());
	EXPECT_EQ(false, cBoard.chckKey());

	cBoard.processCurCode("gmgy");
	EXPECT_EQ("vo__", cBoard.getKeyPrintable());
	EXPECT_EQ(false, cBoard.chckKey());

	cBoard.processCurCode("rrmy");
	EXPECT_EQ("oo__", cBoard.getKeyPrintable());
	EXPECT_EQ(false, cBoard.chckKey());

	cBoard.processCurCode("crgm");
	EXPECT_EQ("vooo", cBoard.getKeyPrintable());
	EXPECT_EQ(false, cBoard.chckKey());

	cBoard.processCurCode("gcrm");
	EXPECT_EQ("vvvv", cBoard.getKeyPrintable());
	EXPECT_EQ(true, cBoard.chckKey());
}

TEST(ExceptionTest, test_setSecret)
{
	CGameBoard cBoard(4, 8);
	EXPECT_THROW(cBoard.setSecret("gcrmm"), MasterMindException);
}

TEST(ExceptionTest, test_chckKey)
{
	CGameBoard cBoard(4, 8);
	EXPECT_THROW(cBoard.chckKey(), MasterMindException);
}

