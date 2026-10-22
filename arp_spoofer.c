#include <sys/socket.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

const uint8_t sock_default_flags = 0;

int main(int argc, char** argv)
{
	int sock_fd = socket(AF_PACKET,SOCK_RAW,sock_default_flags);
	if (sock_fd < 0)
	{
		perror("Socket could not be created");
		return EXIT_FAILURE;
	}
	printf("Socket successfully created!\n");
	close(sock_fd);
	return EXIT_SUCCESS;
}
