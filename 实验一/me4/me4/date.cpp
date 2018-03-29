#pragma once
#include "date.h"
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include "accumulator.h"
using namespace std;
int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int y, int m, int d){
	year = y;month = m;day = d;
	sum = getSum();
}
bool Date::judge(int y){
	return (y % 4 == 0&&y % 100||y % 400 == 0);
}
int Date::getSum(){
	int cnt = year * 365;
	cnt += (year - 1) / 4 + 1;
	cnt -= (year - 1) / 100 + 1;
	cnt += (year - 1) / 400 + 1;
	for(int i = 1; i < month; i++)cnt += md[i];
		if(month > 2&&judge(year))cnt++;
	cnt += day;
	return cnt;
}
bool Date::judgedate(Date b){
	if(sum < b.sum)return 0;
	else return 1;  
}
