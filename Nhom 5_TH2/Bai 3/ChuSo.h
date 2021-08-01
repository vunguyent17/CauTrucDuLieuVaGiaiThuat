#pragma once
#include<iostream>
using namespace std;
#include<string>
#include <sstream>
#include <math.h>

class ChuSo
{
private:
	ChuSo* sPrevious;
	int so;
	ChuSo* sNext;
public:
	ChuSo()
	{
		sPrevious = NULL;
		sNext = NULL;
		so = 0;
	}

	void SetPrevious(ChuSo* a)
	{
		sPrevious = a;
	}

	ChuSo* GetPrevious()
	{
		return sPrevious;
	}
	void SetNext(ChuSo* a)
	{
		sNext = a;
	}

	ChuSo* GetNext()
	{
		return sNext;
	}

	void SetSo(int a)
	{
		so = a;
	}

	int GetSo()
	{
		return so;
	}
	
};

