#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;

int main()
{
	unsigned int round;
	int counta,countg;
	set<char> ans;
	bool g[26];
	string s,sg;
	
	while(scanf("%d",&round)!=EOF)
	{
		if(round==-1)
			break;
		ans.clear();		
		memset(g,false,sizeof(g));
		counta=0;
		countg=0;
		cin.ignore();	
		getline(cin,s);			
		for(int i=0;i<s.length();++i)		
			ans.insert(s[i]);		 //��set�x�s���� �ư����б���
		getline(cin,sg);	
		printf("Round %d\n",round);		
		for(int i=0;i<sg.length();++i)  //�q���r���@�Ӥ@��Ū �@�i�P�_��Ĺ�K���X ��̫��٨S�Nchickened out
		{			
			
			if(!g[sg[i]-'a'])   //�קK����
			{				
				if(*ans.find(sg[i])==sg[i])
					counta++;
				else
					countg++;
				g[sg[i]-'a']=true;
			}
			if(countg>=7)
			{
				printf("You lose.\n");
				break;
			}
			else if(counta==ans.size())
			{
				printf("You win.\n");
				break;
			}
			else if(i==sg.length()-1)
			{
				printf("You chickened out.\n");
				break;
			}			
		}		
	}
	return 0;
}