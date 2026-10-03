#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <net/if.h>
#include <errno.h>
#include "packet_filter.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <interface>", argv[0]);
		return 1;
	}

	char *interface = argv[1];
	struct packet_filter pf;
	if (initialize_packet_filter(&pf, interface) != 0) {
		fprintf(stderr, "Failed to initialize packet filter.");
		return 1;
	}

	printf("Filtering packets on %s...
", interface);
	while (1) {
		process_packet(&pf);
	}
	destroy_packet_filter(&pf);
	return 0;
}
