#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,k,i,jj;
	cin >> n >> k;
	vector< pair<int,int> > v;
	int x,m=0;
	vector<int>adj[n+1];
	for(i=0;i<n;i++)
	{
		cin >> x;
		v.push_back(make_pair(x,i+1));
	}
	sort(v.begin(),v.end());
	if(v[0].firs1!=0 || v[1].first==0){cout << -1 << endl; return 0;}
	int i=1;
	int cnt=0;
	vector<int>prev;
	while(v[i].first==1)
	{
		cnt++;
		adj[v[0].second].push_back(v[i].second);
		prev.push_back(v[i].second);
		i++;
	}
	if(cnt>k){cout << -1 << endl; return 0;}
	int val=2;
	for(i;i<n;i++)
	{
		int j=0;
		int ind=i;
		int z=prev.size();
		while(v[i].first==val && i<n)
		{
			if(adj[prev[j]].size()==k-1){j++; if(j==z){cout << -1 << endl; return 0;};}
			adj[prev[j]].push_back(v[i].second);
			i++;
		}
		prev.clear();
		while(v[i].first==val && i<n)
		{prev.push_back(v[i].second);}
	}
	cout << n-1 << endl;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<adj[i].size();j++)
		{
			cout << i << " " << j << endl;
		}
	}
	return 0;
}