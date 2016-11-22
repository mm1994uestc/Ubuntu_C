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
	cpow(2,2,3,R,I);
	printf("Res_pow=%lf+%lfj\n",*R,*I);
	free(R);
	free(I);
	double array[15]={1,2,9,1,6,2,4,1,4,52,1,3,5,312,8};
	fastsort(array,15);
	int i=0;
	for(i=0;i<15;i++)
	{
		printf("%lf ",array[i]);
	}
	printf("\n");
	return 0;
}
