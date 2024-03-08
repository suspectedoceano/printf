#include "orange_printf.h"
#include <stdio.h>


static void	put_0x(t_data *data)
{
	if ((in("xX", data->format.specifier) &&
			data->format.hash &&
			data->format.buf_tmp[0] != '0') ||
			data->format.specifier == 'p')	
	{
		if (data->format.upper_case)
			putstr_buf_n("0X", 2, data);
		else
			putstr_buf_n("0x", 2, data);

	}
}
/*
 * 0x
 * - 
 * +
 * 0b
 * 0
*/

static void	put_sign(t_data *data)
{
	
	if (data->format.base == BASE_16)
		put_0x(data);
	else if (data->format.signed_value)
	{
		if (data->format.is_negative)	
			putchar_buf_n('-', 1, data);
		else if (!data->format.is_negative)
		{
			if (data->format.plus)
				putchar_buf_n('+', 1, data);
			else if (!data->format.plus &&
					data->format.space)
				putchar_buf_n(' ', 1, data);	
		}
	}
}



/*
 * 👑 Kinf foo able to render whatever 
 * 		int in whatever base in buf
 *
 * 		[+ 0#-][width][precision]
*/
void	print_int(t_data *data, union_int_hack int_values)
{
	//TEST
	printf(M"ZEROS=%d\nSPACES=%d"RST"\n", 
			data->format.padding_zeros, 
			data->format.padding_spaces);
	
	// 1° int->1992 write alpha of it into tmp_buf
	//   📦 str representation of my int
	itoa_buf(data, int_values);
	

	// 2° Find out padding_spaces and padding_zeros
	set_padding_zeros(data);
	set_padding_spaces(data);



	//3° write in buf 📦 the number
	if (data->format.left_justified)
	{
		//1° Sign to write	
		put_sign(data);

		//2° zeros
		putchar_buf_n('0', data->format.padding_zeros, data);

		//3° the actual number
		putstr_buf_n(data->format.buf_tmp, data->format.nbr_len, data);
	
		//4° spaces
		putchar_buf_n(' ', data->format.padding_spaces, data);
	
	}
	else
	{
		//1° spaces
		putchar_buf_n(' ', data->format.padding_spaces, data);
	
		//2° Sign to write	
		put_sign(data);

		//3° zeros
		putchar_buf_n('0', data->format.padding_zeros, data);

		//4° the actual number
		putstr_buf_n(data->format.buf_tmp, data->format.nbr_len, data);
	}
}
