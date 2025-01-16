/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:58:58 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 16:59:20 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_striteri - Applies a function to each character of a string.
 * @s: The string to iterate over.
 * @f: The function to apply to each character. The function takes two arguments:
 *     an unsigned int representing the index of the character, and a char* 
 *     representing the character itself.
 *
 * Description: This function iterates over each character of the string 's' and 
 * applies the function 'f' to each character. The function 'f' is called with 
 * the index of the character and a pointer to the character itself. The iteration 
 * stops when the null-terminator is encountered.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
