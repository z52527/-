#pragma once
#include <iostream>
using namespace std;
class Date{
	protected:
		int year, month, day;
	public:
		int sum;
		Date(){};
		Date(int y, int m, int d);
		int getSum();
		int getdate(Date b);//获得两个日期差
		int getyear() { return year; }
		int getmonth() { return month; }
		int getday() { return day; }
		bool judge(int y);//判断闰年
		bool judgedate(Date b);//判断日期合法
		const void show(){
			printf("%d-%d-%d\n", year, month, day);
		}
};
