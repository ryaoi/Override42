
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>

int auth(char *username, unsigned int serial) {

	int idx = strcspn(username, "\n");
	username[idx] = 0x00;

	int len = strnlen(username, 32);
	if (len <= 5) return 1;

	if (ptrace(0, 0, 1, 0) == 0xff) {
		puts("TAMPERING DETECTED!");
		return 1;
	}

	unsigned int v1 = (username[3] ^ 0x1337) + 0x5eeded;
	unsigned int v2, v3, v4;

	for (int i = 0; i < len; i++) {
		if (username[i] <= 0x1f) return 1;
		v2 = username[i];
		v2 ^= v1;
		v3 = (0x88233b2b * v2) >> 32;
		v4 = v2 - v3;
		v4 = v4 >> 1;
		v4 += v3;
		v4 = v4 >> 10;
		v4 *= 0x539;
		v4 = v2 - v4;

		v1 += v4;

	}
	if (v1 == serial)
		return (0);
	else
		return (1);
}


int main() {

	char username[32];
	unsigned int serial;
	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	puts("Enter login: ");
	fgets(username, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	puts("Enter serial: ");
	scanf("%u", &serial);

	if (auth(username, serial) == 0) {

		puts("Authenticated!");
		system("/bin/sh");
		return EXIT_SUCCESS;
	}
	else
		return EXIT_FAILURE;
}
