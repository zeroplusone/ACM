/*
Sample Input
1  //case
3   //�T�����
Fred Barney   //�֩M�֦����B��
Barney Betty
Betty Wilma

Sample Output
2     //��ӤH���@�P�B�Ͱ�
3
4

SOL:disjoint tree ���ӵ��X�_�Ӧ��h�j
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<string>
#include<cstring>
using namespace std;

#define MAX 200010
int p[MAX];
int rank[MAX];
int num[MAX];

void makeset(int x)
{
	p[x]=x;
	rank[x]=0;
	num[x]=1;
}

int findset(int x)
{
	if(x!=p[x])
		p[x]=findset(p[x]);
	return p[x];
}

int link(int x,int y)
{
	if(x==y)
		return num[x];
	else
	{
		if(rank[x]>rank[y])
		{	
			p[y]=x;	
			num[x]=num[x]+num[y];
			return num[x];
		}
		else
		{
			p[x]=y;
			if(rank[x]==rank[y])
				rank[y]++;
			num[y]=num[y]+num[x];
			return num[y];
		}	
	}
}

int main()
{
	map<string,int> to;
	
	int n,m,c,max;
	string a,b;
	scanf("%d",&c);
	for(int cc=0;cc<c;++cc)
	{
		scanf("%d",&n);
		to.clear();	m=0;

		for(int j=0;j<n;++j)
		{
			cin>>a>>b;
			if(!to.count(a))
			{
				to[a]=m;
				
				makeset(m);
				m++;
			}
			if(!to.count(b))
			{
				to[b]=m;
				
				makeset(m);
				m++;
			}
			printf("%d\n",link(findset(to[a]),findset(to[b])));
		}

	}
	return 0;	
}