#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "date.h"
using namespace std;
class save {
	private:
		double balance, rate, sum, all;
		Date Ldate;
		string id;
		static double tot;
		void getsum(Date &date){
			sum += (date.getdate(Ldate)) * balance;
		}
		double refresh(Date &date, double delta){
			getsum(date);
			delta = (double)floor(0.5+delta*100) / 100;
			//balance += delta;
			Ldate = date;
			return delta;
		}
	public:
		save(){};
		save(Date &d, string i, double r);
		string getid(){return id;}
		double getbalance(){return balance;}
		double getrate(){return rate;};
		void show();
		int deposit(Date &date, double x);
		int withdraw(Date &date, double x);
		double settle(Date &date);
		void getall();
};