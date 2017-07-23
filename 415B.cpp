#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,f;
	cin >> n>>f;
	long long int p[n],q[n];
	long long int sum=0;
	for(int i=0;i<n;i++)
	{
		cin >> p[i] >> q[i];
		sum+=min(p[i],q[i]);
	}
	vector<long long int>v;
	for(int i=0;i<n;i++)
	{
		if(p[i]<q[i])
		{
			v.push_back(min(p[i],q[i]-p[i]));
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	f=min(f,(int)v.size());
	for(int i=0;i<f;i++)
	{
		sum+=v[i];
	}
	cout << sum << endl;
	return 0;
}
