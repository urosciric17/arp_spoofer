arp_spoofer: arp_spoofer.c
	gcc -Wall arp_spoofer.c -o arp_spoofer
	sudo setcap cap_net_raw+ep ./arp_spoofer 

clean:
	rm arp_spoofer
