#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int dp[5001]={0};
int n;
int a[5001],b[5001]={0};
vector<int>v[5001];
int main()
{
	cin >> n;
	int i,j;
	for(i=0;i<n;i++){cin >> a[i];v[a[i]].push_back(i);}
	dp[n]=0;
	int ans=0;
	for(i=n-1;i>=0;i--)
	{
		if(v[a[i]][0]<i)
		{
			dp[i]=dp[i+1];
		}
		else
		{
			int x=v[a[i]].size()-1;
			int y=v[a[i]][x];
			int m=y;
			int exor=0;
			int cnt=0;
			for(j=i;j<=y;j++)
			{
			    if(v[a[j]][0]>=i){m=max(m,v[a[j]][v[a[j]].size()-1]);}
			    else{ dp[i]=dp[i+1];cnt=1;break;}
			}
			if(cnt==0)
			{
			    for(j=i;j<=m;j++)
			    {
				    if(b[a[j]]==1){continue;}
				    else
				    {
					    exor=exor^a[j];
					    b[a[j]]=1;
				    }
			    }
			    for(j=i;j<=m;j++){b[a[j]]=0;}
			    dp[i]=max(exor+dp[m+1],dp[i+1]);
			}
		}
		ans=max(ans,dp[i]);
	}
	cout << ans << endl;
	return 0;
}