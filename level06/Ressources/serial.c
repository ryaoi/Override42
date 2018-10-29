
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char username[32] = {0};

	puts("Enter login: ");
	fgets(username, 32, stdin);

	int idx = strcspn(username, "\n");
	username[idx] = 0x00;

	int len = strnlen(username, 32);
	if (len <= 5) return 1;

	unsigned int v1 = (username[3] ^ 0x1337) + 0x5eeded;
	unsigned int v2, v3, v4;

	for (int i = 0; i < len; i++) {
		if (username[i] <= 0x1f) return 1;
		v2 = username[i];
		v2 ^= v1;
		v3 = 0x88233b2b * (uint64_t)v2 >> 32;
		v4 = v2 - v3;
		v4 = v4 >> 1;
		v4 += v3;
		v4 = v4 >> 10;
		v4 *= 0x539;
		v4 = v2 - v4;

		v1 += v4;
		v1 &= 0xffffffff;
	}
	printf("serial:%u\n", v1);
	return (1);
}
