#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int dp[100001][549];
int a[100001];
int main()
{
	int n;
	cin >> n;
	int i,j;
	vector<int> v;
	vector<int> p;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			v.push_back(i);
			if(i!=n/i){ p.push_back(n/i);}
		}
	}
	reverse(p.begin(),p.end());
	for(i=0;i<p.size();i++){ v.push_back(p[i]); }
		int l=0;
	for(i=1;i<=n;i++){ cin >> a[i]; if(a[i]==1){l++;} }
	if(l==n){cout <<"YES" << endl; return 0;}
	for(i=0;i<v.size();i++)
	{
		for(j=1;j<=n;j++)
		{
			int k=j;
			int cnt=0;
			if( n/v[i] >=3 && dp[j][i]==0)
			{
			  for(k;k<=n;)
			  {
			  	if(a[k]==1)
			  	{	
			  		k+=v[i];
			  		if(k==n){}
			  		else{k%=n;}	
			  	}
			  	else{ cnt=0; break;}
			  	if(k==j){cnt=1;break;}
			  }	
			  if(cnt==1)
			  {
			  	cout <<"YES" << endl;
			  	return 0;
			  }
			  else
			  {
			  	 for(k=j;k<=n;)
			 	 {
			 	 	dp[k][i]=-1;
			 	 	k+=v[i];
				 }	
			  }
			}

		}
	}
	cout <<"NO" << endl;
	return 0;
}