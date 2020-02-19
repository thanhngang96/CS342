#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class TimeSpan
{
private:
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	int const minInSec = 60;
	int const hourInMin = minInSec * 60;
public:
	//constructor
	TimeSpan();
	TimeSpan(double hr, double min, double sec);
	TimeSpan(double min, double sec);
	TimeSpan(double sec);
	~TimeSpan();
	//getter
	bool setTime(int hr, int min, int sec);
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
	//verb
	void timeConvert(int totalSec);
	//OP overload
	friend ostream & operator << (ostream &output, const TimeSpan &duration);
	friend istream & operator >> (istream &input, TimeSpan &duration);	
	TimeSpan operator=(const TimeSpan &duration);
	TimeSpan operator+=(const TimeSpan &duration);
	TimeSpan operator-=(const TimeSpan &duration);
	TimeSpan operator+(const TimeSpan &duration) const;
	TimeSpan operator-(const TimeSpan &duration) const;
	TimeSpan operator-();
	bool operator==(const TimeSpan &duration) const;
	bool operator!=(const TimeSpan &duration) const;
};

