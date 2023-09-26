#pragma once

class DBConnection
{
public:
	DBConnection() {};
	virtual ~DBConnection() = default;
	virtual void open() = 0;
	virtual void close() = 0;
	virtual bool execQuery(char* query) = 0;
};