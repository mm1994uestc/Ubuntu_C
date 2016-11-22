#ifndef __myagorithm_h__
#define __myagorithm_h__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double plyv(double co[],int n,double x);
double pown(double Num,int N);
double sqrt2(double Num,double error);
char ispower2(int num);
int getlines(char s[],int limit);
void cmul(double R1,double I1,double R2,double I2,double *R_res,double *I_res);
void cdiv(double R1,double I1,double R2,double I2,double *R_res,double *I_res);
#endif
