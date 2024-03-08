#include "orange_printf.h"
#include <stdio.h>

/*
 *
 * [-][width *]
*/
void	test_char()
{
	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a char "Y"[%c]"RST"\n", 'A'));
	printf(G"\treal_CHARS=%d"RST"\n\n",
			printf("This is a char "G"[%c]"RST"\n", 'A'));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a char "Y"[%10c]"RST"\n", 'A'));
	printf(G"\treal_CHARS=%d"RST"\n\n",
			printf("This is a char "G"[%10c]"RST"\n", 'A'));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a char "Y"[%-10c]"RST"\n", 'A'));
	printf(G"\treal_CHARS=%d"RST"\n\n",
			printf("This is a char "G"[%-10c]"RST"\n", 'A'));

	int	n = 10;
	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a char "Y"[%-*c]"RST"\n", n, 'A'));
	printf(G"\treal_CHARS=%d"RST"\n\n",
			printf("This is a char "G"[%-*c]"RST"\n", n, 'A'));

}


void	test_percent()
{
	int	n = 10;
	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a char "Y"[%-*%]"RST"\n", n));
	printf(G"\treal_CHARS=%d"RST"\n\n",
			printf("This is a char "G"[%-*%]"RST"\n", n));

}

void	test_str()
{
	char	*s = "Special Beam Cannon";
	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a str "Y"[%s]"RST"\n", s));
	printf(G"\treal_CHARS=%d"RST"\n\n",
			printf("This is a str "G"[%s]"RST"\n", s));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a str "Y"[%10s]"RST"\n", s));
	printf(G"\treal_CHARS=%d"RST"\n\n",
			printf("This is a str "G"[%10s]"RST"\n", s));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a str "Y"[%10.3s]"RST"\n", s));
	printf(G"\treal_CHARS=%d"RST"\n\n",
			printf("This is a str "G"[%10.3s]"RST"\n", s));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a str "Y"[%-10.3s]"RST"\n", s));
	printf(G"\treal_CHARS=%d"RST"\n\n",
			printf("This is a str "G"[%-10.3s]"RST"\n", s));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a str "Y"[%*.*s]"RST"\n", 3, 6, s));
	printf(G"\treal_CHARS=%d"RST"\n\n",
			printf("This is a str "G"[%*.*s]"RST"\n", 3, 6,  s));
}


void	test_int()
{
	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[%i]"RST"\n", INT_MIN));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[%i]"RST"\n", INT_MIN));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[%d]"RST"\n", 42));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[%d]"RST"\n", 42));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[%10d]"RST"\n", 42));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[%10d]"RST"\n", 42));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[%-10d]"RST"\n", 42));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[%-10d]"RST"\n", 42));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[%-+10d]"RST"\n", 42));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[%-+10d]"RST"\n", 42));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[% 10d]"RST"\n", 42));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[% 10d]"RST"\n", 42));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[%1d]"RST"\n", 42));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[%1d]"RST"\n", 42));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[%-10.3d]"RST"\n", 42));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[%-10.3d]"RST"\n", 42));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[%- 10.7d]"RST"\n", 42));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[%- 10.7d]"RST"\n", 42));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[% 010.7d]"RST"\n", 42));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[% 010.7d]"RST"\n", 42));


	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[%+-10.7d]"RST"\n", 42));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[%+-10.7d]"RST"\n", 42));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[%- 10.*d]"RST"\n", 1<<12, 42));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[%- 10.*d]"RST"\n", 1<<12, 42));

	printf(Y"\tmine_CHARS=%d"RST"\n",
			piccolo_printf("This is a int "Y"[%0.*d]"RST"\n", 1<<8, 42));
	printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
			printf("This is a int "G"[%0.*d]"RST"\n", 1<<8, 42));
	//GPT
	puts(M"\t\tGPT TESTS"RST);
	 // Test case 1: Crazy combination of width, precision, and flags
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%-+10.4d]"RST"\n", 12345));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%-+10.4d]"RST"\n", 12345));

    // Test case 2: Another crazy combination with leading zeros, width, and precision
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%010.8d]"RST"\n", 9876));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%010.8d]"RST"\n", 9876));

    // Test case 3: Combining different flags with variable precision
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%-+*.*d]"RST"\n", 6, 3, 123));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%-+*.*d]"RST"\n", 6, 3, 123));



	
    // Test case 4: Testing zero-padding, width, and precision with variable width (1<<5)
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%0*.*d]"RST"\n", 1<<5, 2, 42));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%0*.*d]"RST"\n", 1<<5, 2, 42));

    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%0*.*d]"RST"\n", 5, 2, 42));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%0*.*d]"RST"\n", 5, 2, 42));
    


	
	// Test case 5: A combination of left alignment, width, precision, and the '+' flag
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%-+10.5d]"RST"\n", 987654));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%-+10.5d]"RST"\n", 987654));

    // Test case 6: Combining precision and width with a large precision value (1<<10)
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%*.*d]"RST"\n", 8, 1<<10, 123));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%*.*d]"RST"\n", 8, 1<<10, 123));

	// Test case 1: Extremely large width and precision values
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%*.*d]"RST"\n", 100, 50, 12345));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%*.*d]"RST"\n", 100, 50, 12345));

    // Test case 2: Combining multiple flags and variable width (1<<7)
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%-+0*.*d]"RST"\n", 1<<7, 3, 987));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%-+0*.*d]"RST"\n", 1<<7, 3, 987));

    // Test case 3: Large negative width and precision values
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%-1000.500d]"RST"\n", 87654));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%-1000.500d]"RST"\n", 87654));

    // Test case 4: Combining precision, width, and variable precision (1<<11)
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%*.*d]"RST"\n", 15, 1<<11, 98765));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%*.*d]"RST"\n", 15, 1<<11, 98765));

    // Test case 5: Combining multiple flags with large width and precision values
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%-+01000.500d]"RST"\n", 123456));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%-+01000.500d]"RST"\n", 123456));

    // Test case 6: A combination of flags, width, precision, and variable width (1<<6)
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%0*.*d]"RST"\n", 1<<6, 3, 42));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%0*.*d]"RST"\n", 1<<6, 3, 42));

    // Test case 7: Combining multiple flags with variable width (1<<8) and precision
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Crazy: "Y"[%-+*.*d]"RST"\n", 1<<8, 2, 9876));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Crazy: "G"[%-+*.*d]"RST"\n", 1<<8, 2, 9876));

	// Test case 1: Maximum positive integer value
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Max int: "Y"[%d]"RST"\n", INT_MAX));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Max int: "G"[%d]"RST"\n", INT_MAX));

    // Test case 2: Minimum negative integer value
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("Min int: "Y"[%d]"RST"\n", INT_MIN));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("Min int: "G"[%d]"RST"\n", INT_MIN));
}


void	test_ptr()
{
	int n = 42;

    // Test 1
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Basic pointer: "Y"[%p]"RST"\n", &n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Basic pointer: "G"[%p]"RST"\n", &n));

    // Test 2
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Width of 20: "Y"[%20p]"RST"\n", &n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Width of 20: "G"[%20p]"RST"\n", &n));

    // Test 3
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Left-justified with width of 15: "Y"[%-15p]"RST"\n", &n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Left-justified with width of 15: "G"[%-15p]"RST"\n", &n));

    // Test 4
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Alternate form: "Y"[%#p]"RST"\n", &n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Alternate form: "G"[%#p]"RST"\n", &n));

    // Test 5
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Crazy combination: "Y"[%#-20p]"RST"\n", &n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Crazy combination: "G"[%#-20p]"RST"\n", &n));

    // Test 6
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Precision and width: "Y"[%15.8p]"RST"\n", &n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Precision and width: "G"[%15.8p]"RST"\n", &n));

}

void	test_X_x()
{
int n = 255;

    // Test 1
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Hexadecimal lowercase: "Y"[%x]"RST"\n", n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Hexadecimal lowercase: "G"[%x]"RST"\n", n));

    // Test 2
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Hexadecimal uppercase: "Y"[%X]"RST"\n", n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Hexadecimal uppercase: "G"[%X]"RST"\n", n));

    // Test 3
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Padded lowercase: "Y"[%010x]"RST"\n", n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Padded lowercase: "G"[%010x]"RST"\n", n));

    // Test 4
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Zero-padded uppercase: "Y"[%020X]"RST"\n", n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Zero-padded uppercase: "G"[%020X]"RST"\n", n));

    // Test 5
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Precision lowercase: "Y"[%.*x]"RST"\n", 5, n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Precision lowercase: "G"[%.*x]"RST"\n", 5, n));

    // Test 6
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Precision uppercase: "Y"[%.*X]"RST"\n", 8, n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Precision uppercase: "G"[%.*X]"RST"\n", 8, n));

    // Test 7
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Left-justified lowercase: "Y"[%-15x]"RST"\n", n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Left-justified lowercase: "G"[%-15x]"RST"\n", n));

    // Test 8
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Left-justified uppercase: "Y"[%-15X]"RST"\n", n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Left-justified uppercase: "G"[%-15X]"RST"\n", n));

    // Test 9
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Alternate form lowercase: "Y"[%#x]"RST"\n", n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Alternate form lowercase: "G"[%#x]"RST"\n", n));

    // Test 10
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Alternate form uppercase: "Y"[%#X]"RST"\n", n));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Alternate form uppercase: "G"[%#X]"RST"\n", n));

	 // Test 11
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Zero value lowercase: "Y"[%x]"RST"\n", 0));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Zero value lowercase: "G"[%x]"RST"\n", 0));

    // Test 12
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Zero value uppercase: "Y"[%X]"RST"\n", 0));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Zero value uppercase: "G"[%X]"RST"\n", 0));

    // Test 13
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Large value lowercase: "Y"[%x]"RST"\n", 4294967295));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Large value lowercase: "G"[%x]"RST"\n", 4294967295));

    // Test 14
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Large value uppercase: "Y"[%X]"RST"\n", 4294967295));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Large value uppercase: "G"[%X]"RST"\n", 4294967295));

    // Test 15
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Negative value lowercase: "Y"[%x]"RST"\n", -42));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Negative value lowercase: "G"[%x]"RST"\n", -42));

    // Test 16
    printf(Y"\tmine_CHARS=%d"RST"\n",
           piccolo_printf("Negative value uppercase: "Y"[%X]"RST"\n", -42));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n",
           printf("Negative value uppercase: "G"[%X]"RST"\n", -42));
}

void	test_u()
{
	printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("This is a uint "Y"[%-10.3u]"RST"\n", 42));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("This is a uint "G"[%-10.3u]"RST"\n", 42));

    // Test case 2
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("This is a uint "Y"[%- 10.7u]"RST"\n", 42));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("This is a uint "G"[%- 10.7u]"RST"\n", 42));

    // Test case 3
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("This is a uint "Y"[% 010.7u]"RST"\n", 42));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("This is a uint "G"[% 010.7u]"RST"\n", 42));

    // Test case 4
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("This is a uint "Y"[%+-10.7u]"RST"\n", 42));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("This is a uint "G"[%+-10.7u]"RST"\n", 42));

    // Test case 5
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("This is a uint "Y"[%- 10.*u]"RST"\n", 1<<12, 42));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("This is a uint "G"[%- 10.*u]"RST"\n", 1<<12, 42));

    // Test case 6
    printf(Y"\tmine_CHARS=%d"RST"\n", piccolo_printf("This is a uint "Y"[%0.*u]"RST"\n", 1<<8, 42));
    printf(G"\treal_CHARS=%d"RST"\n\n\n\n", printf("This is a uint "G"[%0.*u]"RST"\n", 1<<8, 42));

}

int main()
{
	
	piccolo_printf("%b\n", 42);
	print_piccolo("CHARS");
	test_char();

	print_piccolo("%");
	test_percent();

	print_piccolo("STRING");
	test_str();
	

	print_piccolo("INT");
	test_int();

	
	print_piccolo("U");
	test_u();

	print_piccolo("PTR");
	test_ptr();
	
}
