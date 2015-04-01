/*
Sample Input
2   //case

1    //0-1(m)���d��
-1 0     
-5 -3
2 5
0 0

1
-1 0
0 1
0 0

Sample Output   //�̤֭ӳ̼Хi�H�]�A0-M���d��
0

1
0 1

sol:sort+greedy
��L��e�@��R�Ȥp��  R�ȳ̤j��
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 100010

int ans,now,m;
bool yes;
struct ppair
{
	int l;
	int r;
	bool operator<(const ppair& t)const
	{
		return l==t.l?r<t.r:l<t.l;	
	}
}p[MAX];
int s[MAX];

void find(int num,int end)
{
	int max=0,tmp=num;
	for(int i=num+1;i<now;++i)
	{
		if(p[i].l<=end && p[i].r>max)
		{
			max=p[i].r;
			tmp=i;
			yes=true;             //��l  RE
		}
	}
	if(yes)
	{			
		s[ans++]=tmp;		
		if(p[tmp].r>=m)
			return;
		yes=false;
		find(tmp,p[tmp].r);
	}
	else
		return;	
}


int main()
{
	int c;
	scanf("%d",&c);
	for(int i=0;i<c;++i)
	{
		if(i!=0)
			printf("\n");
		now=0;	ans=0; yes=false;   //�X�� WA
		scanf("%d",&m);
		while(scanf("%d %d",&p[now].l,&p[now].r)!=EOF)
		{
			if(p[now].l==0 && p[now].r==0)
				break;
			now++;
		}		
		sort(p,p+now);		
		find(-1,0);
		
		printf("%d\n",ans);
		for(int j=0;j<ans;++j)
			printf("%d %d\n",p[s[j]].l,p[s[j]].r);		
	}
	return 0;
}