#include "acc.h"
#include "date.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	Date date(2018, 1, 1);
	save accounts[] = {save(date, "z52527", 0.015),save(date, "admin", 0.015)};
	const int n = sizeof(accounts) / sizeof(save);
	accounts[0].deposit(Date(2018, 1, 5), 5000);
	accounts[1].deposit(Date(2018, 1, 25), 10000);
	accounts[0].deposit(Date(2018, 12, 5), 5500);
	accounts[1].withdraw(Date(2018, 12, 20), 4000);
	for(int i = 0; i < n; i++){
		accounts[i].settle(Date(2019, 1, 1));
		accounts[i].getall();
	}
	//savs::getall();
	getchar();
	getchar();
}