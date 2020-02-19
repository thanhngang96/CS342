#include "TimeSpan.h"

TimeSpan::TimeSpan()
{
	timeConvert(0);
}

TimeSpan::~TimeSpan()
{	
}

TimeSpan::TimeSpan(double hr, double min, double sec)
{
	int totalSec = (int)round(hr * hourInMin + min * minInSec + sec);
	timeConvert(totalSec);
}

TimeSpan::TimeSpan(double min, double sec)
{
	int totalSec = (int)round(hours * hourInMin + min * minInSec + sec);
	timeConvert(totalSec);
}

TimeSpan::TimeSpan(double sec)
{
	int totalSec = (int)round(hours * hourInMin + minutes * minInSec + sec);
	timeConvert(totalSec);
}

int TimeSpan::getHours() const
{
	return (int)hours;
}

int TimeSpan::getMinutes() const
{
	return (int)minutes;
}

int TimeSpan::getSeconds() const
{
	return (int)seconds;
}

void TimeSpan::timeConvert(int totalSec)
{
	hours = totalSec / hourInMin;
	totalSec %= hourInMin;
	minutes = totalSec / minInSec;
	totalSec %= minInSec;
	seconds = totalSec;
}

bool TimeSpan::setTime(int hr, int min, int sec)
{
	this->hours = hr;
	this->minutes = min;
	this->seconds = sec;
	int totalSec = (int)round(hours * hourInMin + minutes * minInSec + sec);
	timeConvert(totalSec);
	return true;
}

TimeSpan TimeSpan::operator=(const TimeSpan & duration)
{

	this->hours = duration.hours;
	this->minutes = duration.minutes;
	this->seconds = duration.seconds;
	int totalSec = (int)round((this->hours * hourInMin) +
		(this->minutes * minInSec + this->seconds));
	timeConvert(totalSec);
	return *this;
}

TimeSpan TimeSpan::operator+=(const TimeSpan & duration)
{

	this->hours += duration.hours;
	this->minutes += duration.minutes;
	this->seconds += duration.seconds;
	int totalSec = (int)round((this->hours * hourInMin) +
		(this->minutes * minInSec + this->seconds));
	timeConvert(totalSec);
	return *this;
}

TimeSpan TimeSpan::operator-=(const TimeSpan & duration)
{
	this->hours -= duration.hours;
	this->minutes -= duration.minutes;
	this->seconds -= duration.seconds;
	int totalSec = (int)round((this->hours * hourInMin) +
		(this->minutes * minInSec + this->seconds));
	timeConvert(totalSec);
	return *this;
}


TimeSpan TimeSpan::operator-()
{
	TimeSpan duration;
	duration.hours = -hours;
	duration.minutes = -minutes;
	duration.seconds = -seconds;
	return duration;
}

TimeSpan TimeSpan::operator+(const TimeSpan & duration) const
{
	TimeSpan result = *this;
	result += duration;
	return result;
}

TimeSpan TimeSpan::operator-(const TimeSpan & duration) const
{
	TimeSpan result = *this;
	result -= duration;
	return result;
}


bool TimeSpan::operator==(const TimeSpan & duration) const
{
	return (duration.hours == hours) &&
		(duration.minutes == minutes) &&
		(duration.seconds == seconds);
}
bool TimeSpan::operator!=(const TimeSpan & duration) const
{
	if (*this == duration)
	{
		return false;
	}
	return true;
}

 ostream & operator << (ostream & output, const TimeSpan & duration)
{
	 output << "Hours:" << right << setw(6) << duration.hours;
	 output << ", Minutes: " << setw(3) << duration.minutes;
	 output << ", Seconds: " << setw(3) << duration.seconds;
	return output;
}

 istream & operator >> (istream & input, TimeSpan & duration)
{
	 int hr, min, sec;
	cout << "Enter hour: ";
	input >> hr;
	cout << "Enter minute: ";
	input >> min;
	cout << "Enter second: ";
	input >> sec;
	duration.setTime(hr, min, sec);
	return input;
}
