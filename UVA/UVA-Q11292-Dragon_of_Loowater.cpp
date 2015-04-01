/*
Sample Input:
2 3   //�n�l�� �h�L��
5
4    ->�n�l�Y���|
7
8
4   ->�h�L����
2 1  //�U�@�����
5
5
10
0 0     //����

Output for Sample Input:  //�h�L�n�����������|�~���
11                        //���Τh�L1����1�� �y�̤p����O
Loowater is doomed!       //�����F

sol:greedy ��j�����Y�̤p���O�B
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 20010
int d[MAX];
int k[MAX];
int ans;
int main()
{
	int n,m,count;
	while(scanf("%d %d",&n,&m)!=EOF)
	{	
		if(n==0 && m==0)
			break;
		for(int i=0;i<n;++i)
			scanf("%d",&d[i]);
		for(int i=0;i<m;++i)
			scanf("%d",&k[i]);
		if(n>m)
			printf("Loowater is doomed!\n");
		else
		{
			sort(d,d+n);
			sort(k,k+m);		
			count=0;	ans=0;
			for(int i=0,now=0;i<n;++i)
			{
				for(int j=now;j<m;++j)
				{
					if(d[i]>k[j])
						continue;
					else
					{						
						ans+=k[j];
						now=j+1;     //WA
						count++;
						break;
					}
				}
			}	
			if(count==n)
				printf("%d\n",ans);
			else
				printf("Loowater is doomed!\n");
		}
	}
	return 0;
}