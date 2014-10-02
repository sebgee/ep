/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */
#include <stdio.h>


int testPrimeNumber(int a)      //Detect if the integer a is a prime number and returns 0 if its not and 1 if it is a prime number
{
    for(long i = 2; i<a; i++)
    {
        if(a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void createPrimeNumbers(int *primeNumbers)
{
    int y = 0;
    for(int i = 1; i<100;i++)
        if(testPrimeNumber(i) == 1)
        {
            primeNumbers[y] = i;
            y++;
        }
}

int getPrimeFactor(int a, int *primeNumbers)
{
    //Get first PrimeNumber
    int i = 1; //Start with 2
    while(! a % primeNumbers[i] == 0 ||! i >= a)
    {
        i++;
    }
    return i-1;
}

int main()
{
    //Variablen
    int primeNumbers[100] = {0};
    //Create a Array with Indexes and Primenumbers, the Primenumbers will be stored in 'primeNumbers'
    createPrimeNumbers(&primeNumbers[0]);

    for(int i = 0; i < 100; i++)
    {
        printf("Index: %d\tValue: %d\n",i,primeNumbers[i]);
    }

    printf("%d\n",getPrimeFactor(244, &primeNumbers[0]));

}
