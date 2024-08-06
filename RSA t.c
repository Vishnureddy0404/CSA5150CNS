#include<stdio.h>
#include<math.h>
int main()
{
	int p=3,q=5;
	int n=p*q;
	int k=(p-1)*(q-1);
	int e=3,d=3;
	int m=2;
    int p1=pow(m,e);
	int C=p1%q;
	int p2=pow(C,d);
	int M = p2%q;
	printf("encryption:%d",C);
	printf("deryption:%d",M);
	return 0;
	
	
}
