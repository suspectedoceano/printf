#ifndef ORANGE_PICCOLO_PRINTF
# define ORANGE_PICCOLO_PRINTF

#include <stdio.h> //TODO
#include <stdlib.h> //malloc free
#include <unistd.h> //write
#include <stdarg.h> // variadic stuff
#include <stdbool.h> // false true 
#include <limits.h> // INT_MAX

//Buffer of 4k, 4096 bytes
#define	BUF_SIZE	(1<<12)


// ASCII Colors with BOLD embedded
#define RST "\033[0m"
#define O   "\033[1;33m"  // BOLD Yellow
#define R   "\033[1;31m"  // BOLD Red
#define G   "\033[1;32m"  // BOLD Green
#define Y   "\033[1;33m"  // BOLD Yellow
#define B   "\033[1;34m"  // BOLD Blue
#define M   "\033[1;35m"  // BOLD Magenta


//💡
typedef unsigned char	byte;

// Useful strings
#define	FLAGS			"+ 0-#"
#define	NUMBERS			"0123456789"
#define	SPECIFIERS		"cspdiuxXb%"
#define LOW_SYMBOLS		"0123456789abcdef"
#define UP_SYMBOLS		"0123456789ABCDEF"

/* HACKY STUFF
 * to use only 1 funtion
 * for all ints
*/
typedef union
{
	unsigned long	uint64;
	long			int64;
}	union_int_hack;


// Symbolic error
typedef enum
{
	OK = 0,
	MALLOC_ERROR = -1337,
	PARSE_ERROR = -42,
}		e_error;


typedef enum
{	
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16,

}		e_base;


/*
 * 📦📦📦📦📦📦📦📦📦
 * All the bools [+-' '0#][width][.precision]
*/
typedef struct s_format
{
	//PARSING STUFF 
	//🏁
	bool	left_justified;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero_pad;
	// "csdixXpu..."
	char	specifier;
	//width + precision
	int		width_value;
	int		precision_value;

	//Utils
	//    ⬇︎ = nbr_len 2
	// [2a] 42 in hex
	char	buf_tmp[64];
	int		nbr_len; // tmp_buf index

	bool	upper_case;
	e_base	base;
	int		padding_spaces;
	int		padding_zeros;
	bool	signed_value;
	bool	is_negative;
	bool	is_converted;

}				t_format;

typedef struct s_data
{
	// pointer copy to ftm
	const char	*s;

	// va_list ->va_arg(ap, int);
	va_list		ap;
	
	// chars written
	int 		chars_written;
	
	// [buffer] 📦4k boy HEAP
	char		*buf;
	int			buffer_index;
		
	// All the bools [+-' '0#][width][.precision]
	t_format	format;
}				t_data;


//****************** PROTOTYPES ***************

//👑
int 	piccolo_printf (const char *fmt, ...);
void    print_piccolo(const char *s);



//Utils
void    my_memset(void *ptr, byte value, size_t n);
bool    in(const char *s, char c);
int		s_len(const char *s);

//Parser
int parse_format(t_data *data);

//Buffer
void    write_buf(t_data *data, char c);
void    flush_buf(t_data *data);
void    putchar_buf_n(char c, int precision, t_data *data);
void    putstr_buf_n(char *s, int precision, t_data *data);
void    itoa_buf(t_data *data, union_int_hack int_values);

//Render
void    print_char(t_data *data, int c);
void    print_str(t_data *data, char *s);
void    set_padding_spaces(t_data *data);
void    set_padding_zeros(t_data *data);
void    print_int(t_data *data, union_int_hack int_values);

#endif
