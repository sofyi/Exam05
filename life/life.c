/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:41:36 by slamhaou          #+#    #+#             */
/*   Updated: 2026/05/02 21:59:54 by slamhaou         ###   ########.fr       */
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
			putchar(bord[i][j]);
	    putchar('\n');
	}
}

void Get_bord(int h, int w , char bord[h][w + 1])
{
    int j;
    
    for(int i = 0; i < h; i++)
    {
        j = 0;
        while (j < w)
            bord[i][j++] = ' ';
        bord[i][j] = '\0';
    }
}

void Get_input_fill_bord(int h, int w, char bord[h][w + 1])
{
    char c;
    int x, y, pen;
    
    x = 0;
    y = 0;
    pen = 0;
    while (read(0, &c, 1) > 0)
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
        if (c == 's' && y < h - 1)
            y++;
        if (c == 'd' && x < w - 1)
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
        
        for (int j = 0; j < w; j++)
        {
            neighbours = 0;
            if (i - 1 >= 0 && oldBord[i - 1][j] == '0')
                neighbours++;
                
            if (i + 1 < h && oldBord[i + 1][j] == '0')
                neighbours++;
                
            if (j + 1 < w && oldBord[i][j + 1] == '0')
                neighbours++;
                
            if ( j - 1 >= 0 && oldBord[i][j - 1] == '0')
                neighbours++;
                
            if (i - 1 >= 0 && j - 1 >= 0 && oldBord[i -1][j - 1] == '0' )
                neighbours++;
                
            if (i - 1 >= 0 && j + 1 < w && oldBord[i - 1][j + 1] == '0')
                neighbours++;
                
            if (i + 1 < h && j - 1 >= 0 && oldBord[i + 1][j - 1] == '0' )
                neighbours++;
            if (i + 1 <  h && j + 1 < w && oldBord[i + 1][j + 1] == '0')
                neighbours++;
            if (oldBord[i][j] == ' ' && neighbours == 3)
                Newbord[i][j] = '0';
            else if (oldBord[i][j] == '0' && !(neighbours == 2 || neighbours == 3))
                Newbord[i][j] = ' ';
            else
                Newbord[i][j] = oldBord[i][j];
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
	char New_bord[hei][wid + 1];
    char (*asle)[wid + 1];
    char (*bb)[wid + 1];
    char (*tmp)[wid + 1];
    
    Get_bord(hei, wid, bord);
    Get_bord(hei, wid, New_bord);
    Get_input_fill_bord(hei, wid, bord);

    asle = New_bord;
    bb = bord;
    for(int i = 0; i < iterations; i++)
    {
        tmp = asle;
        asle = bb;
        bb = tmp;
        Get_New_Bord_iterations(hei, wid, bb, asle);

    }
    if (iterations == 0)
        print_bord(hei, wid, bord);
    else
        print_bord(hei, wid, bb);
}
