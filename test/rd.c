#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd,rd;
	char buf[30];

	fd = open("/dev/chrdev",O_RDWR);
	if(fd < 0)
	{
		perror("open");
		_exit(1);
	}

	rd = read(fd,buf,sizeof(buf));
	if(rd < 0)
	{
		perror("read");
		_exit(1);
	}

	printf("The Read contains %s\n",buf);

	close(fd);

	_exit(0);
}

