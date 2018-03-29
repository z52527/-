#include "acc.h"
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
	save A(0, 10010, 0.015);
	save B(11, 10011, 1.0);
	A.deposit(5, 5000);
	A.deposit(45, 5500);
	printf("%d %lf %lf\n", A.getid(), A.getbalance(), A.settle(90));
	getchar();
	getchar();
}