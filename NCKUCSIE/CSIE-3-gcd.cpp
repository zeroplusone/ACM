#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;

int gcd(int a,int b)
{
	if(a==0)
		return b;	
	return gcd(b%a,a);
}

int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if(a>b)
		{
			int tmp;
			tmp=a;
			a=b;
			b=tmp;
		}
		
		printf("%d\n",gcd(a,b));
		//cout<<gcd(a,b)<<endl;		
	}
	return 0;
}

//cin cout����̭����h�@���ˬd���B�� �|TLE