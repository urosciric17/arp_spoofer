#include <sys/socket.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

const uint8_t ETH_HEADER_SIZE = 14;
const uint16_t ETH_PAYLOAD_MAX_SIZE = 1500;
const uint8_t SOCK_DEFAULT_FLAGS = 0;
const uint16_t MAX_ETH_FRAME_SIZE = ETH_HEADER_SIZE + ETH_PAYLOAD_MAX_SIZE;  

int main(int argc, char** argv)
{
	int sock_fd = socket(AF_PACKET,SOCK_RAW,SOCK_DEFAULT_FLAGS);
	if (sock_fd < 0)
	{
		perror("Socket could not be created");
		return EXIT_FAILURE;
	}
	printf("Socket successfully created!\n");
	close(sock_fd);
	return EXIT_SUCCESS;
}
