#include <stdio.h>
#include "myagorithm.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{
	double a=-1.3,b=4.5,c=7.6,d=-3.6;
	double *R=(double *)malloc(sizeof(double)*1);
	double *I=(double *)malloc(sizeof(double)*1);
	cmul(a,b,c,d,R,I);
	printf("Res_mul=%lf+%lfj\n",*R,*I);
	cdiv(a,b,c,d,R,I);
	printf("Res_div=%lf+%lfj\n",*R,*I);
	return 0;
}
