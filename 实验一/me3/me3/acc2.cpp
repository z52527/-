#pragma once
#include "acc.h"
//#include "date.h"
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "accumulator.h"
using namespace std;
double account::tot = 0;
save::save(Date &d, string i, double r) :account(d, i), rate(r), acc(d, 0){ }
void account::show(){
	cout << "Id: " << id << " ,balance: " << balance << " , lastdate:" ;
	Ldate.show();
	printf("\n");
}
int save::deposit(Date &date, double x, string desc) {
	if(!date.judgedate(Ldate)){
		printf("Deposit error\n");
		return 0;
	}
	refresh(date, x, desc);
	acc.change(date, getbalance());
	cout << "add " << x << " on " << id;
	return 1;
}
int save::withdraw(Date &date, double x, string desc){
	if(getbalance() < x||!date.judgedate(Ldate)){
		printf("withdarw error\n");
		return 0;
	}
	refresh(date, -x, desc);
	acc.change(date, getbalance());
	cout << "withdarw " << x << " on " << id;
	return 1;
}
double save::settle(Date &date){
	if (!date.judgedate(Ldate)) {
		printf("date error\n");
		return 0;
	}
	//refresh(date, 0);
	double tmp = acc.getsum(date) * rate / date.getdate(Date(date.getyear() -1, 1, 1));
	if(tmp != 0)
		refresh(date, tmp, "settle");
	acc.reset(date, getbalance());
}
Credit::Credit(Date &date, string id, double credit, double rate, double fee):account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0){}
int Credit::deposit(Date &date, double x, string desc){
	if(!date.judgedate(Ldate)){
		printf("Deposit error\n");
		return 0;
	}
	refresh(date, x, desc);
	acc.change(date, getDebt());
	cout << "add " << x << "on " << id << endl;
	return 1;
}
int Credit::withdraw(Date &date, double x, string desc){
	if(x - getbalance() > credit||!date.judgedate(Ldate)){
		printf("credit error\n");
		return 0;
	}
	refresh(date, -x, desc);
	acc.change(date, getDebt());
	cout << "withdarw " << x << "on " << id << endl;
	return 1;
}
double Credit::settle(Date &date){
	if (!date.judgedate(Ldate)) {
		printf("date error\n");
		return 0;
	}
	//refresh(date, 0);
	double tmp = acc.getsum(date) * rate / date.getdate(Date(date.getyear() -1, 1, 1));
	if(tmp != 0)
		refresh(date, tmp, "settle");
	if(date.getmonth() == 1&&date.getday() == 1)
		refresh(date, -fee, "feeeeeeeee");
	acc.reset(date, getDebt());
}