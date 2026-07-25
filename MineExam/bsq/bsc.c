#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct map
{
    char empt, free, obc;
    int hi, wi;
    char **tab;
}t_map;

void free_map(t_map *map)
{
    if (!map->tab)
        return;
    for (int i = 0; i < map->hi; i++)
        if (map->tab[i])
            free(map->tab[i]);
    free(map->tab);
}

void print_map(t_map *map)
{
    for(int i = 0; i < map->hi; i++)
        printf("%s\n", map->tab[i]);
}

int no_print(char c)
{
    return c > 126 || c < 32;
}

int read_map(t_map *map, FILE *f)
{
    char *line = NULL;
    int cp = 0;

    ssize_t size = getline(&line, &cp, f);
    if (size < 5 || line[size - 1] != '\n')
        return free(line), 1;
    int i = 0;
    map->hi = 0;
    while (i < size - 4 && line[i] >= '0' && line[i] <= '9')
    {
        map->hi = map->hi * 10 + (line[i] - '0');
        i++;
    }
    if (i != size - 4)
        return (free(line), 1);
    map->empt = line[i++];
    map->obc = line[i++];
    map->free = line[i++];
    if (map->hi < 1 || map->empt == map->obc || map->empt == map->free || map->obc == map->free || no_print(map->empt)|| no_print(map->free) || no_print(map->obc))
        return (free(line), 1);
    map->wi = 0;
    for (int i = 0; i < map->hi; i++)
    {
        size = getline(&line, &cp, f);
        if (size < 2 || line[size - 1] != '\n')
    }
}