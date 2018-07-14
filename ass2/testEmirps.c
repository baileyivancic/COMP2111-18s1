#include <stdio.h>
#include <stdbool.h>
#include <gmp.h>
#include "reverse.h"

void testEmirps()
{
	int i = 1;

	FILE *fp = fopen("output2.txt", "w");
	while (i < 10001)
	{
		//printf("yo\n");
		mpz_t temp;
		mpz_init(temp);
		emirp(i, temp);
		unsigned long temp2 = mpz_get_ui(temp);
		fprintf(fp, "%lu\n", temp2);
		i++;
		printf("%d\n", i);
	}
	fclose(fp);
}
