/** added for native port **/
#include <windows.h>

int gettimeofday(struct timeval *tv, int *ignore)
{
    unsigned _int64 curtime;
    FILETIME filetime;
    
    GetSystemTimeAsFileTime(&filetime);

    curtime = ((((_int64) filetime.dwHighDateTime) << 32)
	       + filetime.dwLowDateTime); // to microseconds

    curtime = curtime / 10;
    tv->tv_sec = (curtime % 1000000) & 0xffffffff;
    tv->tv_usec = (curtime / 1000000) & 0xffffffff;
}
 
    
int keepaliveRenew()
{ return 0; }


int keepaliveInit()
{ return 0; }

usleep(int microsecs)
{
    Sleep(microsecs/10);
}



	
	  


	
	  
