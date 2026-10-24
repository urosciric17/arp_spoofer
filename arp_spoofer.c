#include <sys/socket.h>
#include <netinet/if_ether.h>  // For ARP structures, EtherTypes, and Opcodes
#include <net/if_arp.h>        // For hardware types like ARPHRD_ETHER
#include <net/ethernet.h>      // For Ethernet header definitions and ETH_ALEN
#include <arpa/inet.h>         // For htons(), inet_pton(), etc.
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define DEBUG 0

const uint8_t ETH_HEADER_SIZE = 14;
const uint16_t ETH_PAYLOAD_MAX_SIZE = 1500;
const uint8_t SOCK_DEFAULT_FLAGS = 0;
const uint16_t MAX_ETH_FRAME_SIZE = ETH_HEADER_SIZE + ETH_PAYLOAD_MAX_SIZE;  
const uint8_t MAC_ADDR_LEN = 6;
const uint8_t IPV4_ADDR_LEN = 4;
/*const uint16_t ARP_ETHER_TYPE = 0x0806;
const uint16_t ETH_HW_TYPE = 0x0001;
const uint16_t IPV4_PROT_TYPE = 0x0800;*/
 

struct arp_eth_frame
{
	struct ether_header eth_header;
	struct ether_arp arp_payload;
};

int main(int argc, char** argv)
{
	int sock_fd = socket(AF_PACKET,SOCK_RAW,SOCK_DEFAULT_FLAGS);
	if (sock_fd < 0)
	{
		perror("Socket could not be created");
		return EXIT_FAILURE;
	}
	#if DEBUG == 1
	printf("Socket successfully created!\n");
	#endif
	struct arp_eth_frame* eth_arp_frame = malloc(sizeof(struct arp_eth_frame));
	if(eth_arp_frame == NULL)
	{
		perror("Could not allocate the space for the ethernet frame buffer");
		return EXIT_FAILURE;
	}
	#if DEBUG == 1
	printf("Succesffully allocated the space for the frame buffer!\n");
	#endif
	close(sock_fd);
	return EXIT_SUCCESS;
}
