#pragma once
#include "DBConnection.h"
#include "ThatUsesDB.h"
#include <gtest/gtest.h>


class MockConnection : public DBConnection
{
public:
	MOCK_METHOD(void, open, (), (override));
	MOCK_METHOD(void, close, (), (override));
	MOCK_METHOD(void, execQuery, (char* query), (override));
};

TEST(DBConnectionTest, test1)
{
	MockConnection mconnection;

	EXPECT_CALL(mconnection, saveState).Times(::testing::AtLeast(1));
	EXPECT_CALL(mconnection, restoreState).Times(::testing::AtLeast(1));

	EXPECT_CALL(mconnection, open).Times(::testing::AtLeast(1));
	EXPECT_CALL(mconnection, close).Times(1);
	EXPECT_CALL(mconnection, execQuery).Times(1);
}