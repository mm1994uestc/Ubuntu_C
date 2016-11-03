#include <stdio.h>
#include "myagorithm.h"

int main(void)
{
	float Number;
	printf("Please enter a new number for calculating:");
	scanf("%f",&Number);
	printf("The result we calculate is equal to:%f\n",sqrt2((double)Number,0.0001));
	return 0;
}
