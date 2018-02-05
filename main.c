#include "inc/ft_printf.h"
#include "libft/includes/libft.h"

int main()
{

	//ft_printf("Hello %d, poi %p; string %s fini\n", 42, NULL, "bonjour");
	/*
	write(1, "\n----------\n", 15);
	ft_printf("Hello%----4cla vie\n", 0);
	write(1, "\n----------\n", 14);
	ft_printf("%c\n", 0);
	write(1, "\n----------\n", 13		);*/
	ft_printf("ret %d\n", printf("{%}"));
	ft_printf("--\n");
	ft_printf("ft ret %d\n", ft_printf("{%}"));
	return 0;
}
