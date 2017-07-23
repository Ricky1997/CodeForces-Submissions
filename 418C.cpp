#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int dp[27][1509][1509]={0};
int f[27][1509]={0};
int main()
{
	string x;
	cin >> n >> x;
	int i,j,m;
	string v[26];
	for(i=0;i<26;i++){v[i]="";}
	for(i=0;i<26;i++)
	{
		char y=char( (int)('a'+i) );
		for(j=0;j<n;j++)
		{
			if(x[j]== y){v[i]+='1';}
			else{v[i]+='0';}
		}
	}
	for(i=0;i<26;i++)
	{
			dp[i][n-1][0]=v[i][n-1]-'0';
			for(j=1;j<=n;j++){dp[i][n-1][j]=1;}
			for(j=n-2;j>=0;j--)
			{
				for(m=0;m<=n;m++)
				{
					if(m==n){dp[i][j][m]=n;}
					else if(m==0)
					{
						if(v[i][j]=='1'){dp[i][j][m]=1+dp[i][j+1][m];}
						else{dp[i][j][m]=0;}
					}
					else
					{
						if(v[i][j]=='1')
						{
							dp[i][j][m]= 1+dp[i][j+1][m];
						}
						else{dp[i][j][m]= 1+dp[i][j+1][m-1];}
					}
				}
			}
			for(m=0;m<=n;m++)
			{
				f[i][m]=0;
				for(j=0;j<=n-1;j++)
				{
					f[i][m]=max(f[i][m],dp[i][j][m]);
				}
			}

	}
	int q,in;
	char ch;
	cin >> q;
	while(q>0)
	{
		cin >> in >> ch;
		int ind= ch-'a';
		cout << f[ind][in] << endl;
		q--;
	}
	return 0;
}
