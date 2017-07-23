#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,w,i;
	cin >> n >> w;
	float a[n],sum=0;
	vector< pair <float,int> > v;
	for(i=0;i<n;i++){cin >> a[i];sum+=ceil(a[i]/2);v.push_back(make_pair(a[i],i));}
	if(w<sum){cout << -1 << endl; return 0;}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(i=0;i<v.size();i++)
	{
		v[i].first=ceil(v[i].first/2);
	}
	w=w-sum;
	i=0;
	while(w>0 && i<n)
	{
		if(floor(a[v[i].second]/2)<w)
		{
			w-=floor(a[v[i].second]/2);
			v[i].first+=floor(a[v[i].second]/2);
		}
		else
		{
			v[i].first+=w;
			break;
		}
		i++;
	}
	int ans[n];
	for(i=0;i<v.size();i++)
	{
		ans[v[i].second]=v[i].first;
	}
	for(i=0;i<n;i++){cout << ans[i] << " ";}
	return 0;

}