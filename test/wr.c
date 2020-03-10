#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd,wr;
	char buf[] = "hai this is sriram";

	fd = open("/dev/chrdev",O_RDWR);
	if(fd < 0)
	{
		perror("open");
		_exit(1);
	}

	wr = write(fd,buf,sizeof(buf));
	if(wr < 0)
	{
		perror("write");
		_exit(1);
	}

	close(fd);
	_exit(0);
}
