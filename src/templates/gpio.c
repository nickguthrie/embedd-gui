#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main() {

    char s_0[] = “0″;
    char s_1[] = “1″;
    int fd;

//toggle pg9 LED gpio

    if((fd=open(“/sys/devices/virtual/misc/sun4i-gpio/pin/pg9″,O_RDWR))<0) return(1);
    else {

	while(1) {

	    if(write(fd,s_1,strlen(s_1))<0) return(1);
	    if(write(fd,s_0,strlen(s_0))<0) return(1);
	};

	if(close(fd)<0) return(1);

    }
}
