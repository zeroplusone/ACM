/*
Sample Input 
1      //case
6        //�ӫ~�U��
400 100 200 350 300 250   //$

Sample Output  //�R�T�e�@ �y�̤j���馩
400

SOL:greedy �Ƨǫ�q�̤j���C�T�ӤT�ӶR �T�Ӥ��̫K�y���e�`�X

*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 20010
int buy[MAX];

int main()
{
	int t,n,ans;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		scanf("%d",&n);
		for(int j=0;j<n;++j)
			scanf("%d",&buy[j]);
		sort(buy,buy+n);
		ans=0;
		for(int k=0,now=n-3;k<n/3;++k,now-=3)
			ans+=buy[now];
		printf("%d\n",ans);
	}
	return 0;
}