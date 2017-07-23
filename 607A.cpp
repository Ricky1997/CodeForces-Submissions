#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int dp[100009];
int n;

int main()
{
	cin >> n ;
	int x,y;
	vector< pair<int,int> > v;
	for(int i=0;i<n;i++)
	{
		cin >> x >> y;	
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	dp[0]=0;
	for(int i=1;i<n;i++)
	{
		int x=lower_bound(v.begin(),v.end(),make_pair(v[i].first-v[i].second,0))-v.begin()-1;
		if(x==-1)
		{
			dp[i]=i;
		}
		else
		{
			dp[i]=i-x-1+dp[x];
		}
	}
	int ans=n;
	for(int i=0;i<n;i++)
	{
		ans=min(ans,dp[i]+n-i-1);
	}	
	cout << ans << endl;
	return 0;
}