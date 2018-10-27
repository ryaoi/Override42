

void decrypt(int v) {
	char str[] = "Q}|u`sfg~sf{}|a3";
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		str[i] = str[i] ^ v;
	}
	if (strcmp("Congratulations!", str) == 0) {
		system("/bin/sh");
	}
	else {
		puts("Invalid Password!");
	}
}

void test(int userinput, int constant) {

	int result;
	int ret;

	result = constant - userinput;

	if (result <= 0x15) {
		void *ptr = (void*)(result << 2);
		ptr += 0x80489f0;   // the switch table of decrypt
		goto (*ptr)(result); // go to the function decrypt with result as param
	}
	else {
		decript(rand());
	}
	return;
}
int main()
{
	int userinput;
	printf("Password: ");
	scanf("%d", &userinput);
	test(userinput, 0x1337d00d);
	return EXIT_SUCCESS;
}
