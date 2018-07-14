// Program to find the n'th emirp
// An emirp is prime number, with the reverse also being prime, but is not a palindromic prime
// Completed from program refinement - Nabil Shaikh and Bailey Ivancic
// COMP2111 18s1 - Assignment 2

#define USEGMP
#include <stdio.h>
#include <stdbool.h>
#include <gmp.h>
#include "reverse.h"

void emirp(unsigned long n, mpz_t k);
void testEmirps();

int main(int argc, char* argv[])
{
    testEmirps();
    
    unsigned long placeNum = atoi(argv[1]);

    mpz_t x; //nth emirp will be stored in here
    mpz_init(x); //initialises variable
    emirp(placeNum, x);

    gmp_printf("%Zd\n", x);
    return 0;
}
void emirp(unsigned long n, mpz_t x)
{
    //Declare variables
    mpz_t k;
    mpz_t r;
    
    //Initialise variables (Both will be set to 0)
    mpz_init(k);
    mpz_init(r); 
         
  
    //Set values
    mpz_set_ui(x, 1);

    while (mpz_cmp_ui(k, n) < 0) //GMP comparison function, returns negative if op1 >= op2
    {
      bool e = false;
      while (e == false)
      {
          mpz_add_ui(x, x, 1);
          int p = mpz_probab_prime_p(x, 30); //gmp primality testing function
          if (p != 0)
          {
            reversen(x, r); //r now contains reversed order of x's digits
            
            int t = mpz_probab_prime_p(r, 30); //gmp primality testing function
            if (t != 0) // t == TRUE
            {
              if (mpz_cmp(x, r)) //Guard against palindromic primes
              {
                e = true;
              }
            }
          }
      }
      mpz_add_ui(k, k, 1);
    }
}

void testEmirps()
{
    int i = 1;
    FILE *fp = fopen("output1.txt", "w");
    while (i < 1001)
    {
        mpz_t temp;
        mpz_init(temp);
        emirp(i, temp);
        unsigned long temp2 = mpz_get_ui(temp);
        fprintf(fp, "%lu\n", temp2);
        i++;
    }
    fclose(fp);
}
