#include <stdio.h>

static int MyPow(int Num,int N);
int main(void)
{
	int Number;
	printf("Please enter a new number for calculating:");
	scanf("%d",&Number);
	printf("The result we calculate is equal to:%d\n",MyPow(Number,3));
	return 0;
}
static int MyPow(int Num,int N)
{
	int i=0,Res=1;
	for(i=0;i<N;i++)
	{
		Res*=Num;
	}
	return Res;
}
