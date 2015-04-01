/*
Sample Input 
3 2   //���I�� ���
0 1
1 2
15 16    //case 2
0 2
1 2
2 3
3 4
3 5
4 6
5 7
6 8
7 8
7 9
8 10
9 11
10 12
11 12
10 13
12 14
0 0    //end

Sample Output //�̪����|
2
12

SOL:TRACEBACK 
NOTICE:���I�i���ܦh�� ��u��@�� �GVISIT����
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

#define MAX 30
int r[MAX][MAX];
bool v[MAX][MAX];	//��u�ਫ�@�� ���I�i�ܦh�� �G������
int n,m,ans;
void backtrack(int node,int level)
{
	if(level>ans)
		ans=level;
	
	for(int i=0;i<n;++i)
	{
		if(r[node][i]==1 && !v[node][i])
		{			
			v[node][i]=v[i][node]=true;
			backtrack(i,level+1);
			v[node][i]=v[i][node]=false;			
		}
	}
}

int main()
{
	int a,b;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)
			break;	
		
		memset(r,0,sizeof(r));
		
		for(int i=0;i<m;++i)
		{
			scanf("%d %d",&a,&b);
			r[a][b]=r[b][a]=1;
		}
		
		ans=0;
		for(int j=0;j<n;++j)
		{
			memset(v,false,sizeof(v));			
			backtrack(j,0);
		}
		printf("%d\n",ans);
	}
	return 0;
}
