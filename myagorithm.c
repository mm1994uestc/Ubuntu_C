/*
** function: double plyv(double co,int n,double x)
** func is: p(x)=A1*x^nA2*x^(n-1)+...+A(n-1)*x^1+An.
** co respect the coffecient of the ply func.
** n is the elements of the func.
** x is the input variable of func.
*/
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
/*
** function: double pown(double Num,int N)
** func is: p(Num)=Num^N.
** Num is the variable value of func.
** N is the Times Num times itself.
*/
double pown(double Num,int N)
{
	int i=0;
	double Res=1;
	for(i=0;i<N;i++)
	{
		Res*=Num;
	}
}
/*
** function: double sqrt2(double Num,double erroe=0.001)
** Num is the Number to be sqrt of func.
** error is the minutes between to result in func(respect the different).
** error will be set to be 0.001 if you don't set it.
*/
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
