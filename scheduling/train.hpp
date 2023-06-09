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
};

class train
{
public:
	int plataform;
	tTime arrival;
	tTime departure;
};

#endif