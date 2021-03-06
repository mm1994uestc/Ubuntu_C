#include "myagorithm.h"
/***********************************************************************
** function: double plyv(double co,int n,double x)
** func is: p(x)=A1*x^nA2*x^(n-1)+...+A(n-1)*x^1+An.
** co respect the coffecient of the ply func.
** n is the elements of the func.
** x is the input variable of func.
***********************************************************************/
double plyv(double co[],int n,double x)
{
	int i=0;
	double Res=0;
	for(i=0;i<n;i++)
	{
		Res+=Res*x+co[i];
	}
	return Res;
}
/***********************************************************************
** function: double pown(double Num,int N)
** func is: p(Num)=Num^N.
** Num is the variable value of func.
** N is the Times Num times itself.
***********************************************************************/
double pown(double Num,int N)
{
	int i=0;
	double Res=1;
	for(i=0;i<N;i++)
	{
		Res*=Num;
	}
	return Res;
}
/***********************************************************************
** function: double sqrt2(double Num,double erroe=0.001)
** Num is the Number to be sqrt of func.
** error is the minutes between to result in func(respect the different).
** error will be set to be 0.001 if you don't set it.
***********************************************************************/
double sqrt2(double Num,double error)
{
	int i=0;
	double r=Num/2,guess,diff=0;
	do{
		guess=Num/r;
		r=(guess+r)/2;
		diff=(r-guess)>0 ? (r-guess) : (guess-r);
	}while(diff>error);
	return guess;
}
/***********************************************************************
** function: char ispower2(int num)
** num is a number you want to test whether it is the result of pow(2,n).
** The return of the function shows whether the number is the power of 2.
***********************************************************************/
char ispower2(int num)
{
	return ((num&(num-1)==0) && num>0);
}
/***********************************************************************
** function: int getlines(char s[],int limit)
** s[] is the array you except to storage the input of the Keyboard.
** limit is the length of the array'space apply with command malloc.
***********************************************************************/
int getlines(char s[],int limit)
{
	int i=0,c=getchar();
	do{
		if(c!='\n' && c!=EOF){
			s[i++]=c;
		}
		c=getchar();
		if(c=='\n' || c==EOF){
			break;
		}
	}while(i<limit);
	s[i]='\0';
	return i;
}
/***********************************************************************
** function: void cmul(double R1,double I1,double R2,double I2,double *R_res,double *I_res).
** R1 is the real part of complex number1.
** I1 is the imag part of complex number1.
** R2 is the real part of complex number2.
** I2 is the imag part of complex number2.
** R_res is the real part calculate by two complex numbers: real(Number1*Number2).
** I_res is the real part calculate by two complex numbers: imag(Number1*Number2).
***********************************************************************/
void cmul(double R1,double I1,double R2,double I2,double *R_res,double *I_res)
{
	*R_res=R1*R2-I1*I2;
	*I_res=R1*I2+R2*I1;
}
/***********************************************************************
**
**
***********************************************************************/
void cdiv(double R1,double I1,double R2,double I2,double *R_res,double *I_res)
{
	double Div=R2*R2+I2*I2;
	*R_res=(R1*R2+I1*I2)/Div;
	*I_res=(I1*R2-R1*I2)/Div;
}
/***********************************************************************
**
**
***********************************************************************/
void cpow(double R,double I,int N,double *R_res,double *I_res)
{
	double d=0.0,r=0.0,Theta=0.0;
	r=sqrt(R*R+I*I);
	d=pown(r,N);
	Theta=atan2(I,R);
	*R_res=d*cos(Theta*N);
	*I_res=d*sin(Theta*N);
}
/**********************************************************************
**
** sqrt(complex number)
**********************************************************************/
void csqrtn(double x,double y,int n,double u[],double v[])
{
	int k;
	double r,q,t;
	if(n<1) return ;
	q=atan2(y,x);
	r=sqrt(x*x+y*y);
	if(r+1.0!=1.0)
	{
		r=(1.0/n)*log(r);
		r=exp(r);
	}
	for(k=0;k<=n-1;k++)
	{
		t=(2.0*k*3.1415926+q)/n;
		u[k]=r*cos(t);
		v[k]=r*sin(t);
	}
	return ;
}
/**********************************************************************
**
** exp(complex number)
**********************************************************************/
void cexp(double x,double y,double *u,double *v)
{
	double p;
	p=exp(x);
	*u=p*cos(y);
	*v=p*sin(y);
	return ;
}
/**********************************************************************
**
** ln(complex number)
**********************************************************************/
void clog(double x,double y,double *u,double *v)
{
	double p;
	p=log(sqrt(x*x+y*y));
	*u=p;
	*v=atan2(y,x);
	return ;
}
/**********************************************************************
** Most bad conditions make the time complex to be O(N*logN)
** Fast array sort Function!
**********************************************************************/
void fastsort(double array[],int n)
{
	int boundary=0;
	if(n<2) return;
	boundary=middle_index(array,n);
	fastsort(array,boundary);
	fastsort(array+boundary+1,n-boundary-1); 
}
int middle_index(double array[],int len)
{
	int P1=0,P2=len-1;
	double prov=array[0],temp=0.0;
	while(1)
	{
		while(P1<P2 && array[P2]>=prov) P2--;
		while(P1<P2 && array[P1]<=prov) P1++;
		if(P1==P2) break;
		temp=array[P1];
		array[P1]=array[P2];
		array[P2]=temp;
	}
	if(array[P1]>=prov) return 0;
	array[0]=array[P1];
	array[P1]=prov;
	return P1;
}
/***********************************************************************
**
**
***********************************************************************/
void altesort(double array[],int n)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(array[i]>array[j]) swap(&array[i],&array[j]);
		}
	}
}
void swap(double *N1,double *N2)
{
	double temp=0.0;
	temp=*N1;
	*N1=*N2;
	*N2=temp;
}
/***********************************************************************
**
**
***********************************************************************/
int symbolcount(char str[],char sym)
{
	int count=0,i=0;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]==sym) count+=1;
	}
	return count;
}
/***********************************************************************
**
**
***********************************************************************/
char symbolget(char str[],int index)
{
	if(index<0 || index>strlen(str)) 
	{
		printf("Wrong index input!");
		return -1;
	}
	return str[index];
}
/***********************************************************************
**
**
***********************************************************************/
char * symbolrep(char str[],int index,char Temp)
{
	str[index]=Temp;
	return str;
}
/***********************************************************************
**
**
***********************************************************************/
char * symbolappend(char str[],char app)
{
	int i,Len=strlen(str)+2;
	char *Res=(char *)malloc(sizeof(char)*Len);
	for(i=0;i<Len-2;i++)
	{
		*(Res+i)=str[i];
	}
	*(Res+Len-1)=app;
	*(Res+Len)='\n';
	return Res;
}
