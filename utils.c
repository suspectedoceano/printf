#include "orange_printf.h"


/*
 * strchr, the python way
*/
bool	in(const char *s, char c)
{
	if (NULL == s)
		return false;
	while (*s)
	{
		if (*s == c)
			return true;
		++s;
	}
	return false;
}


/*
 * Recursion
 * 📹  https://youtu.be/4W6CTp1eBe0
*/
int	s_len(const char *s)
{
	if (NULL == s || !*s)
		return 0;
	return s_len(s + 1) + 1;
}


/*
 * 			        	 BUF
 * my memset [[value][value]......[value]] 
*/ 
void	my_memset(void *ptr, byte value, size_t n)
{
	// unsigned chart = byte -> 💡💡💡💡💡💡💡💡
	byte	*ptr_byte;

	ptr_byte = (byte *)ptr;
	while (n)
	{
		*ptr_byte++ = value;
		--n;
	}
}
