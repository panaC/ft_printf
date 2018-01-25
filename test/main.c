#include <stdio.h>

int		main(void)
{

	printf("%-+9dallo\n", 42);
	printf("%-+9dallo\n", -42);
	printf("%-+9dallo\n", 4242);

	printf("%s\n", NULL);
	printf("%p\n", NULL);



	int p;

	void* test;

	test = &p;

	unsigned long long v = (unsigned long long)test;

	printf("%llx\n", v);
	printf("%p\n", test);

	return 0;
}
