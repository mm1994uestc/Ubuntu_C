#include <stdio.h>
#include "myagorithm.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{
	float Number;
	printf("Please enter a new number for calculating:");
	scanf("%f",&Number);
	if(1==Number) printf("You are a foolish man?\n");
	printf("The result we calculate is equal to:%f\n",sqrt2((double)Number,0.0001));
	
	int Array[3][3]={
		{1,0,0},
		{0,1,0},
		{0,0,1},
	};
	int (*Adress2D)[3]=Array;//How to point to the 2-Demension Array.
	int i,j;
	for(i=0;i<3;i++)//Notice that,Exp1:--n>=0 maybe faster than Exp2:n-->=0 in some GCC Compile!
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",*(*(Adress2D+i)+j));
		}
		printf("\n");
	}
	char *p,*q;
	p="I";
	q=p;//Make the two points point to the same adress!
	printf("The String p is:%s\n",p);
	printf("The String q is:%s\n",q);
	q=" LOVE YOU!@SMM";//Get a new adress,will not be the adress before.
	i=strlen(q);
	j=strlen(p);
	char *Str=(char *)malloc(sizeof(char)*(i+j+1));//Notice that the strlen get the length of tring without '\0'.
	strcpy(Str,p);//Those function operation directly on the adress.
	strcat(Str,q);
	printf("The string cat is:%s\n",Str);
	return 0;
}
