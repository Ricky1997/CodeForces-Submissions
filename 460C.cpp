#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
# define  ll long long int 
int a[100009];
int n,m,w;
bool check(ll mid)
{
	int curr=0;
	int mov=0;
	vector< ll > st(n,0);
	for(int i=0;i<n;i++)
	{
		if(i-w>=0)
		{
			curr-=st[i-w];
		}
		if(a[i]+curr<x)
		{
			st[i]=x-a[i]-curr;
			curr+=st[i];
			mov+=st[i];
		}
		if(mov>m){return 0;}
	}
	if(mov<=m){return 1;}
	return 0;
}
int main()
{
	cin >> n >> m >> w;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	ll lo=0;
	ll hi=1000000000000000;
	while(lo<hi)
	{
		ll mid = lo+(hi-lo)/2;
		if(check(mid))
		{
			lo=mid;
		}
		else
		{
			hi=mid-1;
		}
	}


	return 0;	
}