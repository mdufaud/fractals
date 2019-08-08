/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 15:18:34 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 16:27:17 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_CODE_H
# define KEY_CODE_H

# if defined(__APPLE__)
#  define LEFT_CLICK 1
#  define RIGHT_CLICK 2
#  define UP_SCROLL 3
#  define DOWN_SCROLL 4
#  define MIDDLE_CLICK 7
#  define END_KEY 119
#  define LEFT_ARROW 123
#  define UP_ARROW 126
#  define RIGHT_ARROW 124
#  define DOWN_ARROW 125
#  define ESCAPE_KEY 53
#  define PAGE_UP 116
#  define PAGE_DOWN 121
#  define PADFOUR_KEY 86
#  define PADSIX_KEY 88
#  define Q_KEY 12
#  define R_KEY 15
#  define G_KEY 5
#  define B_KEY 11
#  define D_KEY 2
#  define H_KEY 4
#  define C_KEY 8
#  define T_KEY 17
#  define P_KEY 35
#  define S_KEY 1
#  define PAVEPLUS_KEY 69
#  define PAVELESS_KEY 78
#  define CROCHETBEGIN_KEY 33
#  define CROCHETEND_KEY 30
#  define ONE_KEY 18
#  define TWO_KEY 19
#  define THREE_KEY 20
#  define FOUR_KEY 21
#  define LESS_KEY 27
#  define EQUAL_KEY 24
# endif

# if defined(__linux__)
#  define END_KEY 65367
#  define LEFT_ARROW 65361
#  define UP_ARROW 65362
#  define RIGHT_ARROW 65363
#  define DOWN_ARROW 65364
#  define ESCAPE_KEY 65307
#  define PAGE_UP 65365
#  define PAGE_DOWN 65366
#  define PADFOUR_KEY 65430
#  define PADSIX_KEY 65432
#  define Q_KEY 113
#  define R_KEY 114
#  define G_KEY 103
#  define B_KEY 98
#  define D_KEY 100
#  define H_KEY 102
#  define C_KEY 106
#  define T_KEY 116
#  define P_KEY 112
#  define S_KEY 115
#  define PAVEPLUS_KEY 65451
#  define PAVELESS_KEY 65453
#  define CROCHETBEGIN_KEY 91
#  define CROCHETEND_KEY 93
#  define ONE_KEY 49
#  define TWO_KEY 50
#  define THREE_KEY 51
#  define FOUR_KEY 52
#  define LESS_KEY 45
#  define EQUAL_KEY 61
#  define D_KEY 100
# endif

#endif
