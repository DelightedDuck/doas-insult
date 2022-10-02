#include <stdio.h>
#include <string.h>
#include <time.h>

main()
{
    FILE *f;
    int nLines = 0;
    char line[1024];
    int randLine;
    int i;

    srand(time(0));
    f = fopen("file.txt", "r");

/* 1st pass - count the lines. */
    while(!feof(f))
    {
        fgets(line, 1024, f);
        nLines++;
    }

    randLine = rand() % nLines;

/* 2nd pass - find the line we want. */
    fseek(f, 0, SEEK_SET);
    for(i = 0; !feof(f) && i <= randLine; i++)
        fgets(line, 1024, f);

	printf(line);
    return 0;
}
