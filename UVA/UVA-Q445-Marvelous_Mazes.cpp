#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	char c;
	int i;
	while(scanf("%c",&c)!=EOF)
	{		
		if(c=='!')
		{
			printf("\n");
		}
		else if(c==10)
		{
			printf("\n");			
		}
		else
		{
			i=0;
			while(c>='0' && c<='9')
			{
				i+=c-'0';
				scanf("%c",&c);
			}
			for(int j=0;j<i;++j)
			{
				if(c=='b')
					printf(" ");
				else
					printf("%c",c);
			}
		}
	}
	return 0;
}
/*�Ʀr��ܭn�L�X�X�ӫ᭱���r���βŸ� !������ b���Ů�
ps.123T TTTTTT(1+2+3)*/