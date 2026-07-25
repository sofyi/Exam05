#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_bord(int h, int w, char bord[h][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            putchar(bord[i][j]);
        putchar('\n');
    }
}

void Get_bord(int h, int w, char bord[h][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
           bord[i][j] = ' ';
    }
}

void Fill_bord(int h, int w, char bord[h][w])
{
    int p = 0, y = 0, x = 0;
    char c;

    while (read(0, &c, 1) > 0)
    {
        if (c == 'x' && p)
            p = 0;
        else if (c == 'x' && !p)
            p = 1;
        else if (c == 'w' && y > 0)
            y--;
        else if (c == 'a' && x > 0)
            x--;
        else if (c == 's' && y < h - 1)
            y++;
        else if (c == 'd' && x < w - 1)
            x++;
        if ((c == 'x' || c == 'w' || c == 'a' || c == 'd' || c == 's') && p)
            bord[y][x] = 'O';
    }
}

void Fill_iteration(int h, int w,  char copy[h][w] ,char bord[h][w])
{
    int neg;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            neg = 0;
            if (i - 1 >= 0 && bord[i - 1][j] == 'O')
                neg++;
            if (i + 1 < h && bord[i + 1][j] == 'O')
                neg++;
            if (j - 1 >= 0 && bord[i][j - 1] == 'O')
                neg++;
            if (j + 1 < w && bord[i][j + 1] == 'O')
                neg++;
            
            if (i - 1 >= 0 && j - 1 >= 0 && bord[i - 1][j - 1] == 'O')
                neg++;
            if (i - 1 >= 0 && j + 1 < w && bord[i - 1][j + 1] == 'O')
                neg++;
            if (i + 1 < h && j - 1 >= 0 && bord[i + 1][j - 1] == 'O')
                neg++;
            if (i + 1 < h && j + 1 < w && bord[i + 1][j + 1] == 'O')
                neg++;
            
            if (bord[i][j] == 'O' && !(neg == 3 || neg == 2))
                copy[i][j] = ' ';
            else if (bord[i][j] == ' ' && neg == 3)
                copy[i][j] = 'O';
            else
                copy[i][j] = bord[i][j];

        }
    }
}

int main(int ac , char **av)
{
    if (ac != 4)
        return 1;
    int wi = atoi(av[1]);
    int hi = atoi(av[2]);
    int it = atoi(av[3]);

    if (wi <= 0|| hi <= 0 || it < 0)
        return 1;
    char bord[hi][wi];
    char copy[hi][wi];

    Get_bord(hi, wi, bord);
    Get_bord(hi, wi, copy);

    Fill_bord(hi, wi, bord);
    char (*asle)[wi] = bord;
    char (*cp)[wi] = copy;
    char (*tmp)[wi];

    for (int i = 0; i < it; i++)
    {
        Fill_iteration(hi, wi, cp, asle);
        tmp = asle;
        asle = cp;
        cp = tmp;
    }
    print_bord(hi, wi, asle);
}