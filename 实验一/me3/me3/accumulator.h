#pragma once
#include "date.h"
#include <stdio.h>
using namespace std;
class accumulator{
	private:
		Date Ldate;
		double val, sum;
	public:
		accumulator(){};
		accumulator(Date date, double value){
			Ldate = date;val = value;sum = 0;
		}
		double getsum(Date &date){
			 return sum + (date.getdate(Ldate)) * val;
		}
		void change(Date &date, double value){
			sum = getsum(date);
			Ldate = date;
			val = value;
		}
		void reset(Date &date, double value) {
			Ldate = date;
			val = value;
			sum = 0;
		}
};