#ifndef _train_h_
	#define _train_h_

	typedef struct time time;
	typedef struct train train;

	struct time
	{
		int hour;
		int minutes;
	};
	
	struct train
	{
		int platform;
		time arrival;
		time departure;
	};
#endif