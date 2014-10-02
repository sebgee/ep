/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>
#include <stdlib.h>

int isPrimeNumber(int number)
{
    int i = 0;
    for(i = 2; i <= number / 2 ; i++)
    {
        if(number % i == 0)
        {
            return 0;
        }
    }
    /* printf("Found:\t %d\n",i); */
    return 1;
}

int createPrimeNumberArray(int *array, int size)
{
    int y = 0;
    for(int i = 0; y <= size; i++)
    {
        if(isPrimeNumber(i) == 1)
        {
            array[y] = i;
            y++; //only count up the index of the index if a prime number has been added to ensure a full array.
        }
    }
}

int getPrimeFactor(unsigned long *candidate)
{
    //Get a Array of Primenumbers
    int arraySize = 100000;
    int primeNumberArray[arraySize];
    int highFactor = 0;
    createPrimeNumberArray(&primeNumberArray[0], arraySize);

    //Search for a primenumber which is divideable with candidate
    for(int i = 2; i < arraySize; i++)
    {
        if( *candidate % primeNumberArray[i] == 0)
        {
            /* printf("Factor Found! %d\n",primeNumberArray[i]); */
            if(primeNumberArray[i] != 0)
            {
                highFactor = primeNumberArray[i];
            }
        }
    }
    return highFactor;
}

int factorize(int candidate)
{
    /* printf("%d\n",candidate); */
    unsigned long result =  candidate;
    while(result != 1)
    {
        printf("%lu\n",getPrimeFactor(&result));
        result = result / getPrimeFactor(&result);
    }
}

int main(int argc, char *argv[])
{
    unsigned long testnumber = 6008514754;
    printf("Testing: %lu",testnumber);
    factorize(testnumber);
    int testArray[50000];
    createPrimeNumberArray(&testArray[0],50000);

    /* for(int i = 0; i < 1000; i++) */
    /* { */
    /*     printf("%d\n",testArray[i]); */
    /* } */
}
