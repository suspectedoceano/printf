#include "orange_printf.h"


/*        ⬇︎
 * [1234321]
 * 📹 ~https://youtu.be/Dz0qDKVLf5w
*/
static int	my_atoi(t_data *data)
{
	int		value;

	value = 0;
	while (in(NUMBERS, *data->s))
		value = (value * 10) + (*data->s++ - '0');
	return value;
}

/*
 * Don't care how many flags,
 * as we have booleans. Wrong inputs
 * still accettable.
 *                      ⬇︎
 *[0-' '#+++++++++++++00000---- ]
*/
static void	parse_flags(t_data *data)
{
	char	flag;

	while (in(FLAGS, *data->s))
	{
		flag = *data->s;
		if ('0' == flag)		
			data->format.zero_pad = true;
		else if ('+' == flag)
			data->format.plus = true;
		else if (' ' == flag)
			data->format.space = true;
		else if ('#' == flag)
			data->format.hash = true;
		else if ('-' == flag)
			data->format.left_justified = true;

		// ++⬇︎ ptr increase
		++data->s;
	}
}

/*	 ⬇︎
 *	[100] width
 *	
 *	Handy function both for [width][.precision]
*/
static void	get_value(t_data *data, int *value)
{
	if (*data->s == '*')
	{
		// fetching the input value 
		*value = va_arg(data->ap, int);
		++data->s;
		return;		
	}
	*value = my_atoi(data);
}


/*
 *	                                 ⬇︎
 * "All the fucking flags are on??! %[0-' '#+][10][.3]d" , 1992
*/
int	parse_format(t_data *data)
{
	//0° refresh the data ❄️
	//	as this functions is gonna be called
	//	as many times as many '%' in string
	my_memset(&data->format, 0, sizeof(t_format));
	// I can set precision_value to 0, not width
	// 	this -1 is like (no value for precision 🏁)
	data->format.precision_value = -1;

	//💡POSITIONAL approach 1°[🏁] 2°[width] 3°[.prec] 

	// 1° [0-' '#+]
	parse_flags(data);

	// 2°[width *]
	get_value(data, &data->format.width_value);

	// 3°[.precision_value *]
	if (*data->s == '.' && *(++data->s))
		get_value(data, &data->format.precision_value);
			
	// 📍Here I expect a specifier given my implementation
	// 		if not, parse error
	//		   ⬇︎
	// 4° [dipxX..]
	if (!in(SPECIFIERS, *data->s))
		return PARSE_ERROR;
	else
	{
		data->format.specifier = *data->s;
		
		// BASES LOG
		if (in("diu", data->format.specifier))
			data->format.base = BASE_10;
		else if (in("xXp", data->format.specifier))
		{
			data->format.base = BASE_16;
			if ('X' == data->format.specifier)
				data->format.upper_case = true;
		}
		// ...octal, binary...whatever BASE
		// 🔥 New feature 🔥
		else if ('b' == data->format.specifier)
			data->format.base = BASE_2;
	}
	
	// TODO
	printf(M"\nLEFT %d\nPLUS %D\nSPACE %d\nASH %d\n"
			"ZERO_PAD %d\nWIDTH %d\nPRECISION %d\n"
			"SPECIFIER %c"RST"\n",
			data->format.left_justified,
			data->format.plus,
			data->format.space,
			data->format.hash,
			data->format.zero_pad,
			data->format.width_value,
			data->format.precision_value,
			data->format.specifier
			);
	// TODO
	return OK;
}
