#include "orange_printf.h"

/*
 * Badass function to get the padding spaces
*/
static void	set_str_padding_spaces(t_data *data, char *s)
{
	int	len;

	len = s_len(s);

	// 1° check if width ✅
	// 	💡 Can only be > 0
	if (data->format.width_value > 0)
	{	
		// 1° check also if precision ✅
		if (data->format.precision_value >= 0)
		{
			// precision ininfluental if > len 🐞
			if (data->format.precision_value > len)
			{
				data->format.padding_spaces = data->format.width_value - \
									  			len;		  
			}
			// write precise n from str
			// [10.3s] "hello" ->[       hel] 7 spaces
			else if (data->format.precision_value < len)
			{
				data->format.padding_spaces = data->format.width_value - \
										  		data->format.precision_value;	  
			
			}
		}
		// simplest case
		// [%10s] ,"hello" ->[     hello]
		else
		{
			data->format.padding_spaces = data->format.width_value - \
									  		len;	  
		
		}
	}
}




/*
 *
 * 🏁🏁🏁🏁🏁🏁
 * 
 *   🚨
 * [0+ #] 
 *  
 *	I care about these:
 *  	[-]   [width]    [.precision]
*/
void	print_str(t_data *data, char *s)
{
	// 👀 1° check for null
	if (NULL == s)
		s = "(null)";;

	// 2° setting the spaces
	set_str_padding_spaces(data, s);	


	// 3° just write with justification
	if (data->format.left_justified)
	{
		//1° put string
		//	Is the 🏁 precision set?
		//		💡 unset value is -1
		if (data->format.precision_value >= 0)
			putstr_buf_n(s, data->format.precision_value, data);
		else
			putstr_buf_n(s, s_len(s), data);

		//2° Put eventual padding spaces
		//	already precalculated
		putchar_buf_n(' ', data->format.padding_spaces, data);
	}
	// No justification
	// 	Like above just invert the order
	else
	{
		//1° Put eventual padding spaces
		putchar_buf_n(' ', data->format.padding_spaces, data);

		//2° put string
		//	Is the 🏁 precision set?
		if (data->format.precision_value >= 0)
			putstr_buf_n(s, data->format.precision_value, data);
		else
			putstr_buf_n(s, s_len(s), data);
	}

}
