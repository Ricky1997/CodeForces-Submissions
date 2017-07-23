#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int a[5001],s[5001],dp[5001][5001],mp[5001],mn[5001],ans;
int main()
{
	int n,m,k,i,j;	
	cin >> n >> m >> k;
	cin >> a[0];s[0]=a[0];
	for(i=1;i<n;i++){cin >>a[i];s[i]=s[i-1]+a[i];}
	dp[0][0]=0;dp[0][1]=s[m-1];
	for(i=1;i<n;i++)
	{
		dp[i][0]=0;
		if(m+i-1<n)
		{
			dp[i][1]=s[m+i-1]-s[i-1];
		}
		else{dp[i][1]=0;}
	}
	int z=0;
	for(j=1;j<=k-1;j++){mn[j]=0;mp[j]=0;}
	for(i=0;i<n;i++)
	{
		for(j=1;j<=k-1;j++)
		{
			if(i-m>=0){mn[j]=max(mp[j],dp[i-m][j]);}
		}
		for(j=2;j<=k;j++)
		{
			dp[i][j]=0;
			dp[i][j]=max(dp[i][j],mn[j-1]);
			dp[i][j]+=dp[i][1];
		}
		for(j=1;j<=k-1;j++)
		{
			mp[j]=mn[j];
		}
	}
	ans=0;
	for(i=0;i<n;i++)
	{
		ans=max(ans,dp[i][k]);
	}
	cout << ans << endl;
	return 0;
}