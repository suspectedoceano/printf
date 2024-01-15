#include "orange_printf.h"

/*
 *    🤔
 * [🏁🏁🏁🏁]
 *	
 *	I care only bout these:
 *	 [-][width]
*/
void	print_char(t_data *data, int c)
{
	int	width;

	width = data->format.width_value;

	//If width > than the char_len, namely 1
	if (width > 1)
	{
		if (data->format.left_justified)
		{
			//function to pad with spaces
			putchar_buf_n((char)c, 1, data);
			putchar_buf_n(' ', width - 1, data);
		}
		else
		{
			putchar_buf_n(' ', width - 1, data);
			putchar_buf_n((char)c, 1, data);
		}
	}
	//If width == 1 or less, nothing to do
	// but printing the actual char
	else
		putchar_buf_n((char)c, 1, data);
}
