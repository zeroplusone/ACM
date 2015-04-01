/******************
Judge   : POJ
Problem : 1505-Copying Books
Course  : IOI
discribe: m book writen by k man
		  find the minimun of (max of the pages) 
		  If there is more than one solution, print the one that minimizes the work assigned to the first scriber,
			
Input   : 
			2									//n(#case)
			9 3									//m k
			100 200 300 400 500 600 700 800 900	//pages
			5 4									//m k
			100 100 100 100 100					//pages
Output  : 
			100 200 300 400 500 / 600 700 / 800 900	  //cut books by slash
			100 / 100 / 100 / 100 100
Solve   : DP
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXK 510

int dp[MAXK][MAXK];		//dp[i][j] : �ei����j�ӤH�ۼg�A�һݮɶ�(�P���Ʀ�����)���̤p��(1 <= i <= m , 1 <= j <= k)
int cut[MAXK];			//cut[i]   : ��i��slash��b��cut[i]���ѫ�(1 <= i <= k-1)
int sum[MAXK];			//sum[i]   : �ei����(�]�t��i��)���Ҧ�����(1 <= i <= m)

int main()
{
	int n,m,k;
	int i,j,v,in,tmp;
	int minval;
	
	scanf("%d",&n);	//case
	
	while(n--)
	{
		//=======initial========//
		memset(dp,0,sizeof(dp));
		memset(cut,0,sizeof(cut));
		memset(sum,0,sizeof(sum));
		
		
		//=======read========//
		scanf("%d %d",&m,&k);
		for(i=1;i<=m;++i)
		{
			scanf("%d",&in);
			sum[i]=sum[i-1]+in;	//�ei���Ѫ��`�M=�ei-1���Ѫ��`�M+��i���Ѫ�����
			dp[i][1]=sum[i];	//��H��=1�ɡA�������ΡA�t�d�Ҧ�����=sum[i]
		}
		
		//=======dynamic programming========//
		for(i=2;i<=k;++i)					//�q2�ӤH��k�ӤH(i->�H)
		{
			for(j=1;j<=m;++j)				//�q1���Ѩ�m����(j->��)
			{
				if(i>j)	dp[j][i]=0;			//�@�ӤH�ܤ֭n�@���ѡA���s�b�����p
				else						//�p��dp[j][i]
				{			
					minval=dp[j][i-1];		//****
					for(v=j-1;v>=i-1;--v)	//��i�ӤH�n�q������(v)�}�l�۷|�o��̨θ�( i-1 <= v <= j-1 ,�e����i-1�H�ܤ֦��@���ѡA��i�ӤH�ܤ֭n���̫�@��(��j��))
					{						//****from end to start �ݱq�᭱�}�l�j�M�j��A��Ʀr�۵��ɤ~�|���b�̫e��
						tmp=dp[v][i-1]>(sum[j]-sum[v])?dp[v][i-1]:(sum[j]-sum[v]);	//����bv�ɡA��X�e���ӳ������̤j��(dp[v][i-1] �ev���ѡAi-1�ӤH (�e) & v+1���Ѩ�̫�@��(j) sum[j]-sum[v](��) )
						if(minval>=tmp)		//��X���P���k��X�Ӫ��̤p��
						{
							minval=tmp;
						}
					}
					dp[j][i]=minval;		//�O��
				}
			}
		}
		
		//=======cut========//	
		tmp=0;
		for(i=m,j=k-1;i>0 && j>0;--i)		//�q�᭱�}�l���A���`�X�W�L�̤p��(dp[m][k])�ɡA���@�M
		{
			tmp+=sum[i]-sum[i-1];
			if(tmp>dp[m][k] || j>=i)
			{
				cut[j]=i;
				tmp=sum[i]-sum[i-1];
				j--;
			}
		}
		
		//=======print answer========//
		for(i=1,j=1;i<=m;++i)
		{
			if(i!=1)	printf(" ");
			printf("%d",sum[i]-sum[i-1]);
			if(j<k && i==cut[j])
			{
				printf(" /");
				j++;
			}
		}
		printf("\n");
		
	}
	return 0;
}