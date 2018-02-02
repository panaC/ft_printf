#include "inc/ft_printf.h"

int main()
{

	ft_printf("Hello %d, poi %p; string %s fini\n", 42, NULL, "bonjour");
	write(1, "\n----------\n", 15);
	ft_printf("Hello%----4cla vie\n", 0);
	write(1, "\n----------\n", 14);
	ft_printf("%c\n", 0);
	write(1, "\n----------\n", 13);
	return 0;
}
