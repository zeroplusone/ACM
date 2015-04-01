/*
Sample Input
6    //�X�Ӯy��
1 1
1 3
3 3
2 1
3 2
2 2

0

Sample Output
The length of the fence will be 8 units.

���Хu��V�W�U���k��~��򦨪����
��X�@�˺⦹��Y�Φ������+��Y�@�˺⦹�ɧΦ������
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 10010
int ans,n;
struct coor
{
	int x;
	int y;
	bool operator<(const coor &p)const
	{
		return x==p.x?y<p.y:x<p.x;
	}
}p[MAX];

void reset(int n)
{
	ans=0;
	for(int i=0;i<=n;++i)	
		p[i].x=p[i].y=0;	
}

void change()
{
	
	for(int i=0;i<n;++i)		
		swap(p[i].x,p[i].y);
	
}

void getans()
{
		for(int i=1;i<n;i+=2)
		{
			ans+=p[i].y-p[i-1].y;
		}
}

int main()
{	
	while(scanf("%d",&n)!=EOF)
	{		
		if(n==0)
			break;
		reset(n);
		for(int i=0;i<n;++i)
			scanf("%d %d",&p[i].x,&p[i].y);		
		sort(p,p+n);		
		getans();	
		change();
		sort(p,p+n);		
		getans();
		
		printf("The length of the fence will be %d units.\n",ans);
	}
	return 0;
}