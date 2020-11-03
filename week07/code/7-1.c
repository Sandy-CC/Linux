#include"ch7.h"
static void __attribute__ ((constructor)) before_main()
{
	printf("---------------Before Mian---------------\n");
}
static void __attribute__ ((destructor)) after_main()
{
	printf("---------------After Main----------------\n");
}
int main()
{
	printf("---------------Main Function-------------\n");
	return 0;
}
