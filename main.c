#include <stdio.h>
#include "myagorithm.h"
#include "mystack.h"
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
	double array1[13]={1,2,1,3,5,3,2,5,3,3,1,3,1};
	altesort(array1,13);
	for(i=0;i<13;i++)
	{
		printf("%lf ",array1[i]);
	}
	printf("\n");
	StackType A;
	A=NewStack();
	double j=0;
	printf("The data we pushed into the ADT is:");
	for(j=0;j<=1;j+=0.1)
	{
		push(A,j);
		printf("%lf\n",j);
	}
	printf("\n");
	printf("The value with index=2 is:%lf\n",GetStackValue(A,2));
	j=pop(A);
	printf("The data we poped is:%lf\n",j);
	printf("The Depth of the Stack is:%d\n",StackDepth(A)); 
	return 0;
}
