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
		int getyear() { return year; }
		int getmonth() { return month; }
		int getday() { return day; }
		int operator - (Date &date){
			return sum - date.sum;
		}
		bool judge(int y);//判断闰年
		bool judgedate(Date b);//判断日期合法
		const void show(){
			printf("%d-%d-%d", year, month, day);
		}
};
