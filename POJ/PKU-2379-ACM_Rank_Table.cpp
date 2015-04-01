/*    ����ACM����
Sample Input
3 3      //3��3��SUBMIT
1 2 3000 0   //�來 �D�E ��� �O�_AC 
1 2 3100 1
2 1 4200 1

Sample Output  //�ƦW
2 1 3
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAXt 1010 
#define MAXp 30
int c,n;
struct submit
{
	int ci,pi,ti,ri;
	bool operator<(const submit& p)const
	{
		return ti<p.ti;
	}
}s[MAXt];

struct score
{
	int num;
	int ac;
	int time;
	bool ifac[MAXp];
	int tmpt[MAXp];

}team[MAXt];

bool rank(const score a,const score b)     //AC�D�Ʀh->�ɶ��u->�來���X�u
{
	if(a.ac==b.ac)
	{
		if(a.time==b.time)
			return a.num<b.num;
		else
			return a.time<b.time;
	}
	else
		return a.ac>b.ac;
}

void reset()
{
	for(int i=1;i<=c;++i)
	{	
		team[i].num=i;		
		team[i].ac=team[i].time=0;
		for(int j=0;j<MAXp;++j)
		{	
			team[i].tmpt[j]=0;
			team[i].ifac[j]=false;
		}
	}
}

int main()
{	
	while(scanf("%d %d",&c,&n)!=EOF)
	{
		reset();
		for(int i=0;i<n;++i)	
			scanf("%d %d %d %d",&s[i].ci,&s[i].pi,&s[i].ti,&s[i].ri);	
		sort(s,s+n);   //  ->���|�Ӯɶ���
		for(int i=0;i<n;++i)	
		{
			if(s[i].ri)
			{
				if(team[s[i].ci].ifac[s[i].pi])			//�|���ƴ���
					continue;
				else
				{
					team[s[i].ci].ifac[s[i].pi]=true;
					team[s[i].ci].ac++;			
					team[s[i].ci].time+=s[i].ti+team[s[i].ci].tmpt[s[i].pi];
				}
			}
			else
			{
				team[s[i].ci].tmpt[s[i].pi]+=1200;   //�@20����
			}
		}
		sort(team+1,team+c+1,rank);
		printf("%d",team[1].num);    //��X�榡
		for(int j=2;j<=c;++j)		
			printf(" %d",team[j].num);
		
		printf("\n");
	}
	return 0;
}