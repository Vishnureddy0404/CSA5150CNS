#include<stdio.h>
#include<string.h>
#include<ctype.h>
void vigenercipher(char *pt,char *k)
{
	int tl=strlen(pt);
	int kl=strlen(k);
	for(int i=0;i<tl;i++)
	{
		if(isalpha(pt[i]))
		{
		char base=isupper(pt[i])?'A':'a';
		int keyindx=i%kl;
		int shift=tolower(k[keyindx])-'a';
		pt[i]=(pt[i]-base+shift)%26+base;
		}
	}
}
int main()
{
	char pt[1000];
	char k[1000];
	printf("enter pt:");
	scanf("%s",pt);
	printf("enter key:");
	scanf("%s",k);
	vigenercipher(pt,k);
	printf("Cipher Text:%s",pt);
	return 0;
}
