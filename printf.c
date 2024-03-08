/*
 * va_arg, va_start, va_end
*/
#include "orange_printf.h"

/*
 * 🌭🌭🌭🌭🌭🌭🌭
 * WRAPPER for all rendering functions*
 *
*/
void	render_format(t_data *data)
{
	char	specifier;

	specifier = data->format.specifier;
	// Ternary thing
	if ('%' == specifier)
		print_char(data, '%');
	else if ('c' == specifier)		//type promotion
		print_char(data, va_arg(data->ap, int));
	else if ('s' == specifier)
		print_str(data, va_arg(data->ap, char *));

	//..next video
	// "dipxXu" ->> 💡
	// 📦 union to contain all integers
	union_int_hack	int_values;

	// initialize to 0 union
	int_values.int64 = 0;

	if (in("dipxXub", specifier))
	{
		//💡 di -> signed int    -> long ⬆︎ promote 
		//	 p  -> void *        -> unsigned long
		//	 xXu -> unsigned int -> unsigned long ⬆︎ promote
		//

		//1° fetch the data and stock in hacky_union	
		if (in("di", specifier))
		{
			// Save more info 
			int_values.int64 = (long)va_arg(data->ap, int);
			data->format.signed_value = true;
			if (int_values.int64 < 0)
				data->format.is_negative = true;
		}
		else if ('p' == specifier)
			int_values.uint64 = (unsigned long)va_arg(data->ap, void *);
		// 🔥 b is binary, new feature easily added
		else if (in("xXub", specifier))
			int_values.uint64 = (unsigned long)va_arg(data->ap, unsigned int);	
	
	
	
		//2° Call one 👑 function for all
		print_int(data, int_values);	
	}



}

/*
 * Little init function
 * 💡 I copy the string internally the data
 * 		cause I wanna pass ONLY this 📦 to all
 * 		functions.
 * 💡 Buffer is 4k also in the real printf in my sys
*/
static int	init_data(t_data *data, const char *fmt)
{
	data->chars_written = 0;
	data->s = fmt;
	data->buf = malloc(BUF_SIZE * sizeof(char));
	if (NULL == data->buf)
		return MALLOC_ERROR;
	data->buffer_index = 0;
	my_memset(data->buf, 0, BUF_SIZE * sizeof(char));
	return OK;

}


/*
 * TLDR of what is going on
 *	
 *	1° 📦 Make a big box data to pass by reference to all functions
 *	2° 🔄 Loop the string
 *			1) If normal char stock in buf
 *			2) If '%' sentinel, parse stuff
 *				-stock in buf the rendered dat	a
 *	3° 🎬 End flush the buf and clean the shit outta here
 *
*/
int piccolo_printf (const char *fmt, ...)
{
	t_data	data;

	//0° Kick in the variadic machinery & init data
	va_start(data.ap, fmt);	
	if (init_data(&data, fmt))
		return MALLOC_ERROR;

	//🍖🍖🍖
	//                        ⬇︎
	//"Dorigelop crafca means %10.3s" , "fly to"	
	while (*data.s)
	{
		// 1° If stumbled into '%' sentinel'
		// 				💡 Short circuiting
		if (*data.s == '%' && *(++data.s))
		{
			// stock all flags, values in 📦
			if (parse_format(&data))
			{
				//🤔🔥 put piccolo yelling
				print_piccolo("RTFM!");
				free(data.buf);
				return PARSE_ERROR;	
			}
			// render the data properly 
			render_format(&data);
		}
		
		//2°
		else
		{
			// Calling write many times is super bad
			// 📦 stock char in 4k buf
			write_buf(&data, *data.s); //TODO
		}

		// ptr arithmetic, move the ⬇︎
		++data.s;
	}	

	//write output when str over 🎬
	flush_buf(&data);

	//CLEAN UP functions
	va_end(data.ap);
	free(data.buf);

	// return chars_written
	return data.chars_written;
}
