#include "inc/ft_printf.h"
#include "libft/includes/libft.h"
#include <stdio.h>

int main()
{

	//ft_printf("Hello %d, poi %p; string %s fini\n", 42, NULL, "bonjour");
	/*
	write(1, "\n----------\n", 15);
	ft_printf("Hello%----4cla vie\n", 0);
	write(1, "\n----------\n", 14);
	ft_printf("%c\n", 0);
	write(1, "\n----------\n", 13		);*/
	/*ft_printf("ret %d\n", printf("{%}"));
	ft_printf("--\n");
	ft_printf("ft ret %d\n", ft_printf("{%}"));
	*/
	/*ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
			    L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",

				    L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
*/
	printf("%C", 0xbffe);
	printf("\n");
	ft_printf("%C", 0xbffe);
	
	return 0;
}
