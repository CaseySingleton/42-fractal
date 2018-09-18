/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:21:32 by csinglet          #+#    #+#             */
/*   Updated: 2018/08/16 17:21:33 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIN_KEYS_H
# define WIN_KEYS_H

# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_UP				126
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_Q				12
# define KEY_E				14
# define KEY_PLUS			69
# define KEY_MINUS			78
# define KEY_SPACE			49
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

typedef struct			s_keys
{
	int					up;
	int					left;
	int					down;
	int					right;
	int					w;
	int					a;
	int					s;
	int					d;
	int					q;
	int					e;
	int					plus;
	int					minus;
	int					space;
	int					change;
}						t_keys;

#endif
