#include<stdio.h>
#include<math.h>
int main()
{
	int q,x,XA,XB,YA,YB,KA,KB,P1,P2,K1,K2;
	q=3;
	x=5;
	XA=3,XB=5;
	P1=pow(x,XA);
	YA=P1%q;
	P2=pow(x,XB);
	YB=P2%q;
	K1=pow(YB,XA);
	K2=pow(YA,XB);
	KA=K1%q;
	KB=K2%q;
	printf("%d\n",KA);
	printf("%d\n",KB);
	if(KA=KB){
		printf("key is exchanged");
	}
return 0;
}
