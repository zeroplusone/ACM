#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
	char s[1000];

	while(gets(s))
	{	
		char *token=strtok(s," ");//�i�κX�l�P�_�O�_�Ĥ@��

		if(!(strcmp(token,"you")))
			printf("we");
		else
			printf("%s",token);
		token=strtok(NULL," ");
		for(;token!=NULL;token=strtok(NULL," "))
		{
			
			if((!strcmp(token,"you")))
				printf(" we");
			else
				printf(" %s",token);
		}
		printf("\n");
		
	}
	return 0;
}