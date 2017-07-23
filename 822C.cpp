#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n,x;
vector< pair<int,int> >v[200009];
int main()
{
	cin >> n >> x;
	int i,j,l,r,cst;
	int yo=0;
	for(i=0;i<n;i++)
	{
		cin >> l >> r >> cst;
		v[r-l+1].push_back(make_pair(l,cst));
		yo=max(yo,r-l+1);
	}
	for(i=0;i<=yo;i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	int m=INT_MAX;
	for(int d=1;d<x;d++)
	{
        int mn =INT_MAX;
		for (int i=0,j=0;i<v[x-d].size();i++)
        {
			while (j<v[d].size() && v[d][j].first + d - 1 < v[x-d][i].first)
			{
				if (mn > v[d][j].second)
					mn = v[d][j].second;
				j++;
			}
			if (mn != INT_MAX)
			{
				int s = mn + v[x-d][i].second;
				if (m > s)
					m = s;
			}
		}
	}
	if(m==INT_MAX){cout << -1 << endl; return 0;}
	cout << m << endl;
	return 0;
}
