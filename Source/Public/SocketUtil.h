#pragma once

#include "iostream"
using namespace std;


//#define  XXXX(x,...) printf(__VA_ARGS__)

class SocketUtil
{
public:

	static void ReportError() { cout << endl; };

	template<typename T,typename... Args>
	static void ReportError(T value,Args... args)
	{
		cout << value << " ";
		ReportError(args...);
	}


	//template<typename T>
	//static T sum(T t)
	//{
	//	return t;
	//}
	//template<typename T, typename ... Types>
	//static T sum(T first, Types ... rest)
	//{
	//	return first + sum<T>(rest...);
	//}

};