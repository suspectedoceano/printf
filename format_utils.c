#include "orange_printf.h"
#include <stdbool.h>
#include <stdio.h>




/*
 * Set zeros to pad
 * Spaces are in function of zeros
 * so i will count zeros before hand
*/
void	set_padding_zeros(t_data *data)
{
	//👑 precision in the king of zeros
	//📦 buf_tmp[1992]
	//				 ⬆︎ nbr_len = 4
	// Is there a precision? ✅
	if (data->format.precision_value >= 0) 
	{
		// 📦[1992] .prec = 6-> 💡 pad with 2 zeros 001992
		if (data->format.precision_value >= data->format.nbr_len)
		{
			data->format.padding_zeros = data->format.precision_value - \
									 	data->format.nbr_len; 
			return ;
		}	
	}


	// In no precision LAND
	// [0🏁]
	if (data->format.zero_pad)
	{
		// [-] 🚨 wrong input
		if (data->format.left_justified)
			return ;
	
		// I care bout [width]
		// %10 [      1992] 10-4 = 6 zeros
		if (data->format.width_value > data->format.nbr_len)
			data->format.padding_zeros = data->format.width_value - \
										 data->format.nbr_len;

		// Check for signs + or - or ' ' or 0x
		// "dipxX u"
		if (data->format.specifier == 'u')
			return ;

		// [#]
		else if ((in("xX", data->format.specifier) &&
					data->format.hash &&
					data->format.buf_tmp[0] != '0') ||
		   			data->format.specifier == 'p')	
			data->format.padding_zeros -= 2; // because 0x pad
		
		// [- +]
		else if (data->format.is_negative ||
				(!data->format.is_negative && 
				(data->format.plus || data->format.space)))
			data->format.padding_zeros--;
	}
	
	// safety control
	if (data->format.padding_zeros < 0)
		data->format.padding_zeros = 0;
}


void	set_padding_spaces(t_data *data)
{
	// remove zeros
	// 10.5   [     01992]
	data->format.padding_spaces = data->format.width_value - \
								  data->format.padding_zeros - \
								  data->format.nbr_len;

	if (in("uxXp", data->format.specifier))
	{
		// [#]
		if ((in("xX", data->format.specifier) &&
					data->format.hash &&
					data->format.buf_tmp[0] != '0') ||
		   			data->format.specifier == 'p')	
			data->format.padding_spaces -= 2; // because 0x pad

		// easily expandible with other bases
		// ... 0b, 0

		// done with 
		return ;
	}

	// di minus sign
	if (data->format.is_negative)
	{
		data->format.padding_spaces--;
		return ;
	}

	// +
	if (!data->format.is_negative &&
			data->format.plus)
	{
		data->format.padding_spaces--;
		return ;
	}

	// space
	if (!data->format.is_negative &&
		data->format.space)
	{
		data->format.padding_spaces--;
		return ;
	}
}
