#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
# define p 1000000007
int main()
{
	int n,k,d,i,j;
	cin >> n >> k >> d;
	long long int dp[n+1] ={0};
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(i-j >=0)
			{
				dp[i]+=dp[i-j]%p;
				dp[i]%=p;
			}
		}
	}
	long long int dp2[n+1] ={0};
	dp2[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=d-1;j++)
		{
			if(i-j >=0)
			{
				dp2[i]+=dp2[i-j]%p;
				dp2[i]%=p;
			}
		}
	}
	long long int ans = dp[n]%p - dp2[n]%p;
	while(ans%p < 0)
	{
	    ans+=p;
	    ans%=p;
	}
	cout << ans%p << endl; 
}