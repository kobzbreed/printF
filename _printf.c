#include "main.h"
/**
 * _printf - printf function
 *@format: const char pointer
 *Description: this functions implement some functions of printf
 Return: num of characteres printed
 */
int _printf(const char *format, ...)
{
	const char *string;
	int count = 0;
	va_list arg;

	if (!format)
		return (-1);

	va_start(arg, format);
	string = format;

	count = loop_format(arg, string);

	va_end(arg);
	return (count);
}
/**
 *loop_format - loop format
 *@arg: va_list arg
 *@string: pointer from format
 *Description: This function make loop tp string pointer
 Return: num of characteres printed
 */
int loop_format(va_list arg, const char *string)
{
	int i = 0, flag = 0, count_fm = 0, count = 0, check_per = 0;
	
	while (i < _strlen((char *)string) && *string != '\0')
	{
		char aux = string[i];

		if (aux == '%')
		{
			i++, flag++;
			aux = string[i];
			if (aux == '\0' && _strlen((char *)string) == 1)
				return (-1);
			if (aux == '\0')
				return (count);
			if (aux == '%')
			{
				flag++;
			} else
			}
				count_fm = function_manager(aux, arg);
				if (count_fm >= 0 && count_fm != -1)
				{
					i++;
					aux = string[i];
					if (aux == '%')
						flag--;
					count = count + count_fm;
				} else if (count_fm == -1 && aux != '\n')
				{
					count += _putchar('%');
				}

			}
		}
		check_per = check_percent(&flag, aux);
		count += check_per;
		if (check_per == 0 && aux != '\0' && aux != '%')
			count += _putchar(aux), i++;
		check_per = 0;
	}
	return (count);
}
/**
 * check_percent - call function manager
 *@flag: value by reference
 *@aux: character
 *Description: This function print % pear
 *Return: 1 if % is printed
 */
int check_percent(int *flag, char aux)
{
	int tmp_flag;
	int count = 0;

	tmp_flag = *flag;
	if (tmp_flag == 2 && aux == '%')
	{
		_putchar('%');
		tmp_flag = 0;
		count = 1;
	}
	return (count);
}

/**
 * call_function_manager - call function manager
 *@aux: character parameter
 *@arg: va_list arg
 *Description: This function call function manager
 *Return: num of characteres printed
 */

int call_function_manager(char aux, va_list arg)
{
	int count = 0;

	count = function_manager(aux, arg);
	return (count);
}
