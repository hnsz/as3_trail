
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>



/*	Computes pow(base,exponent) % modulo in a fast way	*/
int expmod (int base, int exponent, int modulo)
{

	long long int solution = 1;
	int i;                          
  
	for (i= 31; i>=0; i--) {
	  
		int ithBit = (exponent >> i) & 1;
		
		solution = ( ((solution*solution) % modulo) * (ithBit ? base : 1) ) % modulo;
	}
	
	return (int) solution;
	
}

/*	doubles array, where array[0] is the size of the array	*/
void doubleArraySize (int* array)
{
  
	int newSize = 2*array[0];
	
	array = realloc(array, newSize*sizeof(int));
	assert(array != NULL);
	
	array[0] = newSize;
	
}


/*	Returns array with primefactors of n	*/
void primeFactors (int n, int* primeFactorsArray, int* length)
{
  
	int i;
	int j = 0;
	
	while (n%2 == 0)
	{
		if (j+1 >= primeFactorsArray[0])
			doubleArraySize(primeFactorsArray);
		
		primeFactorsArray[j+1] = 2;
		j++;
		n = n/2;
	}
 
	for (i = 3; i*i <= n; i += 2)
	{
		while (n%i == 0)
		{
			if (j+1 >= primeFactorsArray[0])
				doubleArraySize(primeFactorsArray);
		
			primeFactorsArray[j+1] = i;
			j++;
			n = n/i;
		}
	}
 
	if (n > 2) 
	{
		if (j+1 >= primeFactorsArray[0])
			doubleArraySize(primeFactorsArray);
		
		primeFactorsArray[j+1] = n;
		j++;
	}
	
	*length = j;
	
}



void printGenerators(int prime, int lowbG, int upbG) 
{
	int i,j;
	
	int* qi = malloc(10*sizeof(int)); 
	qi[0] = 10; /*<-- first element is size of array*/
	int length;
	
	primeFactors(prime-1, qi, &length);
	
	
	
	for(i = lowbG; i <= upbG; i++) {
		int isGenerator = 1;
		
		for (j=1; j<=length ;j++)
		{
			if ( expmod(i , (prime-1)/qi[j] , prime ) == 1 ) {
				isGenerator = 0;
				break;
			}
		}
		
		if (isGenerator) 
			printf("%d ",i);
		
	}
}

int main (int argc, char *argv[]) {
	
  
	/*	Exercise 12	*/
	int exponent = 13458;
	int base = 33789;
	int modulo = 99839;
	
	printf("Exercise 12:\npow(%d ,%d) mod %d = %d\n\n", base, exponent, modulo, expmod(base, exponent, modulo));
	
	
	/*	Exercise 13	*/
	int prime = 10007;
	int lowbG = 1, upbG = 10006;
	
	printf("Exercise 13:\nGenerators g for prime %d, where %d <= g <= %d :\n", prime, lowbG, upbG);
	printGenerators(prime, lowbG, upbG);
	printf("\n\n");
	
	/*	Exercise 14	*/
	
	printf("Exercise 14:\n");
	/*
	printf("493: %d\n",517*943 %493);
	printf("517: %d\n",493*943 %517);
	printf("943: %d\n",517*493 %943);
	
	
	int k=1;
	int m = 943, n = 254881, q;
	
	while ((m*k + 1)%(n%m) != 0) {
		k++;
	}
	
	q = (m*k + 1)/(n%m);
	printf("\n%d\n",q);
	*/
	
	long long int x1 = (long long int) 20 * 487531 *  75;
	long long int x2 = (long long int)382 * 464899 * 156;
	long long int x3 = (long long int)622 * 254881 * 515;
	
	int M = 493 * 517 * 943;
	printf("\n%lld +\n%lld +\n%lld =\n%lld mod M\n", x1,x2, x3, (x1+x2+x3) % M);
	printf("cuberoot(13824) = 24\n");
	
	
	
	return 0;
}


