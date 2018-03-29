#pragma once
#include "acc.h"
#include "date.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include "accumulator.h"
#include <algorithm>
using namespace std;
int main(){
	/*save A(Date(2018, 1, 1), "10010", 0.015);
	A.deposit(Date(2018, 1, 5), 5000, "asag");
	A.deposit(Date(2018, 1, 25), 5500,"asdfasdg");
	cout << A.getid();
	printf(" %lf %lf %lf\n", A.getTotal(), A.getbalance(), A.settle(Date(2018, 1, 30)));
	getchar();
	*/
	cout << "Test save:" << endl;
	Date date1(2018, 1, 1);
	save savingaccount(date1, "z52527", 0.015);
	savingaccount.show();
	Date date2(2018, 1, 5);
	savingaccount.deposit(date2, 5000, "test1");
	Date date3(2018, 2, 14);
	savingaccount.deposit(date3, 5500, "test2");
	Date date4(2018, 3, 31);
	savingaccount.settle(date4);
	Date date5(2018, 4, 10);
	savingaccount.withdraw(date5, 2000, "test3");
	Date date6(2018, 5, 15);
	savingaccount.settle(date6);
	printf("\nTest credit \n");
	Credit creditaccount(date1, "admin",   3000, 0.035, 150);
	creditaccount.show();
	Date date7(2018, 1, 15);
	creditaccount.withdraw(date7, 250,  "test4");
	Date date8(2018, 2, 1);
	creditaccount.settle(date8);
	Date date9(2018, 2, 3);
	creditaccount.deposit(date8, 255, "test4");
	Date date10(2018, 2, 7);
	creditaccount.withdraw(date9, 5000, "test5");
	creditaccount.withdraw(date9, 360, "test6");
	Date date11(2018, 3, 1);
	creditaccount.settle(date11);
	Date date12(2018, 3, 4);
	creditaccount.deposit(date12, 371, "test7");
	Date date13(2019, 1, 1);
	creditaccount.settle(date13);
	getchar();
	getchar();
	return 0;
}