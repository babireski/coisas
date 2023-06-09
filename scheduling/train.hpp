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
	int platform;
	tTime arrival;
	tTime departure;
	std::string print()
	{
		std::string ret = "Plataforma: ";
		ret += std::to_string(platform) + " " + std::to_string(arrival.hour) + ":" + std::to_string(arrival.minutes);
		return ret;
	}
};

#endif