// Dupla: Elian Babireski & Pedro Vargas

#ifndef _train_hpp
#define _train_hpp

class tTime
{
public:
	int hour;
	int minutes;
	bool isValid(int h, int m)
	{
		if ((h <= 24 || h >= 0) && (m >= 0 || m <= 59))
			return true;
		else
			return false;
	}
	bool isLess(tTime t2)
	{
		return(hour < t2.hour || (hour == t2.hour && minutes < t2.minutes));
	}
};

class train
{
public:
	tTime arrival;
	tTime departure;

};
bool compareTimes(train t1, train t2)
{
	return t1.departure.isLess(t2.departure);
}
#endif