#include <stdio.h>
#include <stdlib.h>
void factorize(unsigned long testNumber)
{
    int divisor = 2;
    while(testNumber != 1)
        if(testNumber % divisor == 0) {
            printf("%d\n",divisor);
            testNumber = testNumber / divisor;
        }
    else {
        divisor++;
    }
}

int main(int argc, char *argv[]) {
    /* unsigned long testNumber = atoi(argv[1]); */
    unsigned long testNumber = 600851475143;
    printf("%lu\n-----\n", testNumber);
    factorize(testNumber);


}
