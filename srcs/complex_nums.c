/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 16:12:38 by csinglet          #+#    #+#             */
/*   Updated: 2018/08/10 16:12:39 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

complex_num		com_new(double real, double imaginary)
{
	complex_num		new_com;

	new_com.real = real;
	new_com.imaginary = imaginary;
	return (new_com);
}

complex_num		com_sum(complex_num a, complex_num b)
{
	complex_num		sum;

	sum.real = a.real + b.real;
	sum.imaginary = a.imaginary + b.imaginary;
	return (sum);
}

/*
**	For multiplication of complex numbers given a + bi and i^2 = -1
**
**	product = (a + bi) * (c + di)
**	product = (a * c) + (adi + cbi) + ((b * d) * i^2)
**	product = (a * c) + (adi + cbi) - (b * d)
**	OR
**	product = (a * c) - (b * d) + (adi + cbi) <- new complex number
**	prodcuts real value = (a * c) - (b * d)
**	products imaginary value = adi + cbi
*/

/*
**	int a
**	int b
*/

complex_num		com_multi(complex_num a, complex_num b)
{
	complex_num		product;

	product.real = (a.real * b.real) - (a.imaginary * b.imaginary);
	product.imaginary = (a.real * b.imaginary) + (a.imaginary * b.real);
	return (product);
}

/*
**	Square root an multiplication is taxing. Add as much as possible
*/

float			com_dist_from_origin(complex_num com)
{
	return (sqrtf((com.real * com.real) + (com.imaginary * com.imaginary)));
}
