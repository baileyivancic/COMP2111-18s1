#include "dict.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getIndex (char c);

void newdict(Dict * T)
{
	Dict node = malloc(sizeof(struct __tnode__));

	node->eow = FALSE;
	int i = 0;
	while (i < VECSIZE)
	{
		node->cvec[i] = NULL;
		i++;
	}

	*T = node;
}

void addword (const Dict r, const word w)
{
	if (strlen(w) == 0) {
		//printf("set true %s\n", w);
		r->eow = TRUE;
		return;
	}

	Dict curr = r;
	char* buf = w;

	int i = getIndex(w[0]);
	if (curr->cvec[i] == NULL) {
		//printf("create %s\n", w);
		newdict(&curr->cvec[i]);
		buf++;
		//printf("continue %s->%s\n", w, buf);
		addword(curr->cvec[i], buf);
	} else {
		buf++;
		//printf("continue %s->%s\n", w, buf);
		addword(curr->cvec[i], buf);
	}
}

bool checkword (const Dict r, const word w)
{
	if ( strlen(w) == 0 ) {
		if ( r->eow == TRUE ) {
			//printf("found %s\n", w);
			return TRUE;
		} else {
			//printf("not found %s\n", w);
			return FALSE;
		}
	} else {
		char* buf = w;
		buf++;
		int i = getIndex(w[0]);
		if (r->cvec[i] == NULL) {
			//printf("not there %s\n", w);
			return FALSE;
		}
		//printf("continue %s->%s\n", w, buf);
		return checkword(r->cvec[i], buf);
	}
}

void delword (const Dict r, const word w)
{
	if ( strlen(w) == 0 ) {
		r->eow = FALSE;
	} else {
		char* buf = w;
		buf++;
		int i = getIndex(w[0]);
		if (r->cvec[i] == NULL) return;
		delword(r->cvec[i], buf);
	}
}

int getIndex (char c)
{
	return c - 'a';
}

void barf(char *s)
{
	fprintf(stderr, "%s", s);
}
