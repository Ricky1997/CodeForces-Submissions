#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector < pair<long long int,long long int> > v;
	int i;
	long long int x,y;
	for(i=0;i<n;i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	long long int mf[n];
	mf[1]=v[0].second;
	for(i=2;i<n;i++)
	{
		mf[i]=max(v[i-1].second,mf[i-1]);
	}
	int ans=0;
	for(i=1;i<n;i++)
	{
		if(v[i].second<mf[i]){ans++;}
	}
	cout << ans << endl;
	return 0;
}