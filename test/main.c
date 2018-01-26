#include <stdio.h>

int		main(void)
{

	printf("%+01dallo\n", 42);
	printf("%+09dallo\n", 42);
	printf("%+09dallo\n", -42);
	printf("%+09dallo\n", 4242);
	printf("%+09.7dallo\n", 4242);
	printf("%09dallo\n", 4242);
	printf("%09.7dallo\n", 4242);
	printf("%+09dallo\n", 123456789);
	printf("%+09dallo\n", 42);
	printf("%+09dallo\n", -42);
	printf("%+09dallo\n", 0);
	printf("%-+9dallo\n", 42);
	printf("%-+9dallo\n", -42);
	printf("%-+9dallo\n", 4242);
	printf("%-+9dallo\n", 123456789);
	printf("%+9dallo\n", 42);
	printf("%+9dallo\n", -42);
	printf("%+9dallo\n", 0);
	printf("%+09.3dallo\n", 42);
	printf("%+09dallo\n", -42);
	printf("%+09dallo\n", 4242);
	printf("%30.20dallo\n", 123456789);
	printf("%30.20dallo\n", 0);
	printf("%30.0dallo\n", 0);
	printf("%30dallo\n", 123456789);
	printf("%030dallo\n", 123456789);
	printf("%030.20dallo\n", 123456789);
	printf("%+30.20dallo\n", 123456789);
	printf("%+09dallo\n", 42);
	printf("%+09dallo\n", -42);
	printf("%+09dallo\n", 0);
	printf("%-+9dallo\n", 42);
	printf("%-+9dallo\n", -42);
	printf("%-+9dallo\n", 4242);
	printf("%-+9dallo\n", 123456789);
	printf("%+9dallo\n", 42);
	printf("%+9dallo\n", -42);
	printf("%+9dallo\n", 0);
	printf("%s\n", NULL);
	printf("%p\n", NULL);
	printf("%30.20sallo\n", "pierre");
	printf("%30sallo\n", "pierre");
	printf("%030sallo\n", "pierre");
	printf("%030.20sallo\n", "pierre");
	printf("%+30.20sallo\n", "pierre");
	printf("%30.20sallo\n", "pierrepierrpierrepierrepierreepierre");
	printf("%30sallo\n", "pierrepierpierrepierrepierrerepierre");
	printf("%30.0callo\n", '\0');
	printf("%30.20pallo\n", NULL);
	printf("%30pallo\n", NULL);



	int p;

	void* test;

	test = &p;

	unsigned long long v = (unsigned long long)test;

	printf("%llx\n", v);
	printf("%p\n", test);

	return 0;
}
