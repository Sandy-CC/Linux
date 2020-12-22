#include "ch11.h"

int main()
{
	time_t timer;
	timer = time((time_t*)0);
	printf("%s\n", ctime(&timer));

	sleep(2);
	// time_t timer2;
	// timer2 = time((time_t*)0);
	printf("%s\n", ctime(&timer));

	return 0;
}