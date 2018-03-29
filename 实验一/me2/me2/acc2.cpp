#include "acc.h"
#include "date.h"
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
double save::tot = 0;
save::save(Date &d, string i, double r){
	rate = r, sum = 0, balance = 0, id = i, Ldate = d;
}
void save::show(){
	printf("剩余%d元\n", balance);
}
int save::deposit(Date &date, double x){
	if(!date.judgedate(Ldate)){
		printf("Deposit error\n");
		return 0;
	}
	double tmp = refresh(date, x);
	balance += tmp;tot += tmp;
	return 1;
}
int save::withdraw(Date &date, double x){
	if(balance < x||!date.judgedate(Ldate)){
		printf("withdarw error\n");
		return 0;
	}
	double tmp = refresh(date, x);
	balance -= tmp;tot -= tmp;
	return 1;
}
double save::settle(Date &date){
	if (!date.judgedate(Ldate)) {
		printf("date error\n");
		return 0;
	}
	refresh(date, 0);
	double tmp = sum * rate / 365;
	sum = 0;
	balance += tmp;
	tot += tmp;
	return tmp;
}
void save::getall(){
	cout << getid() << endl;
	printf("Balance:%.2lf\n", balance);
	printf("Total balance: %.2lf\n", tot);
}