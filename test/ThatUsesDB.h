#pragma once
#include "DBConnection.h"

class ThatUsesDB
{
private:
	DBConnection* connect;

public:
	ThatUsesDB() {};
	~ThatUsesDB() {};

	void openConnection()
	{
		connect->open();
	};
	void useConnection(char* query)
	{
		connect->execQuery(query);
	};
	void closeConnection()
	{
		connect->close();
	};
};