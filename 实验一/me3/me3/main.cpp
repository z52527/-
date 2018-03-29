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
	save A(Date(2018, 1, 1), "10010", 0.015);
	A.deposit(Date(2018, 1, 5), 5000, "asag");
	A.deposit(Date(2018, 1, 25), 5500,"asdfasdg");
	cout << A.getid();
	A.settle(Date(2019, 1, 30));
	A.show();
	printf("%lf %lf\n", A.getTotal(), A.getbalance() );
	getchar();
}