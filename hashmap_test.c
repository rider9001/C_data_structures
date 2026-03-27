#include <stdio.h>
#include <stddef.h>
#include <sys/time.h>

#include "inc/vector.h"

unsigned long getMicrotime()
{
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (unsigned long)1e6 + currentTime.tv_usec;
}

int main()
{
    

    return 0;
}