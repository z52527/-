#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "accumulator.h"
#include "date.h"
using namespace std;
class account{
	private:
		double balance;
		static double tot;
	protected:
		Date Ldate;
		string id;
		account(){};
		account(Date &date, string i){
			Ldate = date;
			id = i;
			balance = 0;
			cout << "id " << i << " is created.\n" << endl;
		}
		void refresh(const Date &date, double delta, string desc){
			delta = (double)floor(0.5+delta*100) / 100;
			//balance += delta;
			Ldate = date;
			balance += delta;
			tot += delta;
			cout << "before: " << balance - delta << " , now: " << balance << " because: " << desc << endl;
		}
		const void error(string msg){cout << msg << endl;}
	public:
		const string getid(){return id;}
		const double getbalance(){return balance;}
		//const double getrate(){return rate;};
		void show();
		static double getTotal(){return tot;}
};

class save : public account{
	private:
		double rate;
		accumulator acc;
	public:
		save(){};
		save(Date &d, string i, double r);
		//string getid(){return id;}
		//double getbalance(){return balance;}
		double getrate(){return rate;};
		//void show();
		int deposit(Date &date, double x, string desc);
		int withdraw(Date &date, double x, string desc);
		double settle(Date &date);
		//double getall(Date &date);
};
class Credit : public account{
	protected:
		accumulator acc;
		double credit, rate, fee;
	public:
		Credit(){};
		Credit(Date &date, string id, double credit, double rate, double fee);
		const double getDebt(){
			double x = getbalance();
			return x < 0 ? x : 0;
		}
		const double getcredit() {return credit; }
		const double getRate(){return rate;}
		const double getFee(){return fee;}
		const double getAvailable() {
			if (getbalance() < 0)
				return credit + getbalance();
			else
				return credit;
		}
		int deposit(Date &date, double x, string desc);
		int withdraw(Date &date, double x, string desc);
		double settle(Date &date);
		//double getall(Date &date);
};