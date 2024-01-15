#include "orange_printf.h"

/*
 * 👑
 * Function to convert all int | uint in a string
 * in whatever BASE
 * ~https://youtu.be/fK48rdwzzD4?si=ycwHH3NvQRk3Wqbt atoi_base (similar principles)
 * ~https://youtu.be/4W6CTp1eBe0?si=gzx4S5z1Dzh2pzZm Recursion
 * ~https://www.youtube.com/watch?v=oIvvrRxa2Wk putnbr recursive
*/
void	itoa_buf(t_data *data, union_int_hack int_values)
{
	union_int_hack	tmp;
	
	// 0° check BASE
	if (data->format.base < 2 || data->format.base > 16)
		return ;

	// RECURSION
	// 1° check if the number is negative
	if (data->format.is_negative && !data->format.is_converted)
	{
		//Inversion
		int_values.int64 = -(int_values.int64);
		data->format.is_converted = true;
		itoa_buf(data, int_values);	
	}
	
	//⬇︎  EVERYTHING FROM HERE IS READ AS UNSIGNED ⬇︎
	// 2° BASE CASE
	else if (int_values.uint64 < data->format.base)
	{
		// "xX"
		if (data->format.upper_case)
			data->format.buf_tmp[data->format.nbr_len++] = UP_SYMBOLS[int_values.uint64];
		else
			data->format.buf_tmp[data->format.nbr_len++] = LOW_SYMBOLS[int_values.uint64];	
	}
	// 3° RECURSION
	else
	{
		tmp.uint64 = int_values.uint64 / data->format.base;
		itoa_buf(data, tmp);
		tmp.uint64 = int_values.uint64 % data->format.base;
		itoa_buf(data, tmp);	
	}
}





/*
 * This function is called in 2 scenarios:
 * 	1° When the loop is over (str over)
 * 	2° When buf is full [4k chars]
 *
 * Before flush ⏱️
 *
 * 	index  ⬇︎  
 * [Random\0                   ]
*/
void	flush_buf(t_data *data)
{
	// write-> flush in stdout + stock chars_written
	// write 📹 ~https://youtu.be/i_qs1w6DBHo 
	data->chars_written += write(STDOUT_FILENO,
								data->buf,
								data->buffer_index); 
	// ❄️ refresh after call ❄️
	// ⬇︎
	// [0000000000000000000000...0] 4k buf
	my_memset(data->buf, 0, BUF_SIZE);
	data->buffer_index = 0;
}


/*		
 *    ⬇︎
 *	"Random integer %d\n", 21
 *		
 *		write_buf()
 *
 *			4K buf
*/
void	write_buf(t_data *data, char c)
{ 
 //                            ⬇︎	
 //  [Ra                ...    ]                      
	if (data->buffer_index == BUF_SIZE)
	{
		//❄️ refresh index and write str in stdout
		flush_buf(data); //TODO
	}
	// Just stock the char in buf
	data->buf[data->buffer_index++] = c;
}


/*
 * Function to write a char n times
 * useful for padding with '0' or ' '
*/
void	putchar_buf_n(char c, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision--)
		write_buf(data, c);
}

/*
 *
 * Function to write a str with a refined control
 * over precision in buf
*/
void    putstr_buf_n(char *s, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	// "hello"->> prec = 3  = "hel"  
	// prec 42? =  hello
	while (precision-- && *s)
		write_buf(data, *s++);

}

