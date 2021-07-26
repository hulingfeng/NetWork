#pragma once

#include "iostream"
using namespace std;


#define  XXXX(x,...) printf(__VA_ARGS__)

class SocketUtil
{
public:
	static void ReportError(int a,...)
	{
		//printf(__VA_ARGS__);
		XXXX(2, "zhangsan %d",5);
		//cout << a << endl;
	}

};