/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:41:36 by slamhaou          #+#    #+#             */
/*   Updated: 2026/04/28 13:29:02 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_bord(int h, int w, char bord[h][w + 1])
{
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
			write(1, &bord[i][j], 1);
		write (1, "\n", 1);
	}
}

void Get_bord(int h, int w , char bord[h][w + 1])
{
    int j;
    int i = 0;

    while(i < h)
    {
        j = 0;
        while (j < w)
            bord[i][j++] = ' ';
        bord[i++][j] = '\0';
    }
}

void Get_input_fill_bord(int h, int w, char bord[h][w + 1])
{
    char c;
    int x, y, pen ,red;
    
    x = 0;
    y = 0;
    pen = 0;
    while (read(0, &c, 1))
    {
        if (c == 'x')
        {
            if (pen == 0)
                pen = 1;
            else
                pen = 0;
        }
        if (c == 'w' && y > 0)
            y--;
        if (c == 'a' && x > 0)
            x--;
        if (c == 's' && y < h)
            y++;
        if (c == 'd' && x < w)
            x++;
        if ((c == 'w' || c == 'a' || c == 's' || c == 'd' || c == 'x') && pen == 1)
            bord[y][x] = '0';
    }
}

void  Get_New_Bord_iterations(int h, int w, char Newbord[h][w + 1] , char oldBord[h][w + 1])
{
    int neighbours = 0;
    
    for(int i = 0; i < h; i++)
    {
        neighbours = 0;
        for(int j = 0; j < w; j++)
        {
            if (j + 1 < w && oldBord[i][j + 1] == '0')
                neighbours++;
            if ( j - 1 <= 0 && oldBord[i][j - 1] == '0')
                neighbours++;
            if ( i - 1 > 0 && oldBord[i - 1][j] == '0')
                neighbours++;
            if ( i + 1 < h && oldBord[i - 1][j] == '0')
                neighbours++;
            if (oldBord[i][j] == '0' && (neighbours == 2 || neighbours == 3))
                Newbord[i][j] = '0';
            if (oldBord[i][j] == ' ' && neighbours == 3)
                Newbord[i][j] = '0';
        }
    }
}
int main(int ac, char **av)
{
	int wid, hei, iterations;
	if (ac != 4)
		return 1;

	wid = atoi(av[1]);
	hei = atoi(av[2]);
	iterations = atoi(av[3]);

    if (hei < 1 || wid < 1 || iterations < 0)
        return 1;
        
	char bord[hei][wid + 1];
	char bord_iterations[hei][wid + 1];
    
	Get_bord(hei, wid, bord);
 	Get_input_fill_bord(hei, wid, bord);
    if (iterations > 0)
    {
        Get_bord(hei,wid,bord_iterations);
        Get_New_Bord_iterations(hei, wid, bord_iterations, bord);
        if (iterations % 2 == 0)
            print_bord(hei, wid, bord);
        else
            print_bord(hei, wid, bord_iterations);
    }
    else
	    print_bord(hei, wid, bord);
}
