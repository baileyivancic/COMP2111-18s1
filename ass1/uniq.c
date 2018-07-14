#include "uniq.h"
#include <stdbool.h>
#include <stdio.h>
#define MAXCHAR 1024

unsigned int uniq(unsigned int n, char *a[], char *b[])
{
    char temp[MAXCHAR]; //Last copied string
    int i = 0; //iterate through array a
    unsigned int k = 0; //iterate through array b

    while (i < n)
    {
        //strcmp(a[i], temp) START
        int j = 0;
        bool same = true;
        while (a[i][j] != '\0' && temp[j] != '\0')
        {
            if (a[i][j] != temp[j])
            {
                same = false;
            }
            j = j + 1;
        }

        //One string is longer at end
        if (a[i][j] != '\0' || temp[j] != '\0')
        {
            same = false;
        }
        //strcmp FINISH

        if (!same)
        {
            //strcpy(b[k],a[i] START
            int m = 0;
            while (a[i][m] != '\0')
            {
                b[k][m] = a[i][m];
                m = m + 1;
            }
            b[k][m] = '\0';
            //strcpy FINISH

            //strcpy(temp, a[i]) START
            m = 0;
            while (a[i][m] != '\0')
            {
                temp[m] = a[i][m];
                m = m + 1;
            }
            temp[m] = '\0';
            //strcpy FINISH

            k = k + 1;
        }
        i = i + 1;
    }
    return k;
}
