#include "acc.h"
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
save::save(int d, int i, double r){
	rate = r, sum = 0, balance = 0, id = i, Ldate = d;
}
void save::show(){
	printf("剩余%d元\n", balance);
}
void save::deposit(int date, double x){
	double tmp = refresh(date, x);
	balance += tmp;
}
void save::withdraw(int date, double x){
	if(balance < x){
		printf("错误，剩余金额不足\n");
		return ;
	}
	double tmp = refresh(date, x);
	balance -= tmp;
}
double save::settle(int date){
	getsum(date);
	double tmp = sum * rate / 365;
	return tmp;
}