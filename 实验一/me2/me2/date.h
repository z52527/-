#pragma once
#include <iostream>
//#include "acc.h"
using namespace std;
class Date{
	private:
		int year, month, day;
	public:
		int sum;
		Date(){};
		Date(int y, int m, int d);
		int getSum();
		int getdate(Date b);//获得两个日期差
		bool judge(int y);//判断闰年
		bool judgedate(Date b);//判断日期合法
};
