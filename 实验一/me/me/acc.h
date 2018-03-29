#include <iostream>
class save {
	private:
		double balance, rate, sum;
		int id, Ldate;
		void getsum(int date){
			sum += (date - Ldate) * balance;
		}
		double refresh(int date, double delta){
			getsum(date);
			delta = (double)floor(0.5+delta*100) / 100;
			//balance += delta;
			Ldate = date;
			return delta;
		}
	public:
		save(){};
		save(int, int, double);
		int getid(){return id;}
		double getbalance(){return balance;}
		double getrate(){return rate;};
		void show();
		void deposit(int date, double x);
		void withdraw(int date, double x);
		double settle(int date);
};