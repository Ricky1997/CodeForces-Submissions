#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
# define p 1000000007
int mark[1001]={0};
int main()
{
	int n,k;
	cin >> n;
	vector<pair<int,pair<int,int>>>v;
	int i,j,x,y;
	for(i=0;i<n;i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(y,make_pair(x,i)));
	}
	cin >> k;
	vector<pair<int,int>>a;
	for(i=0;i<k;i++)
	{
		cin >> x;
		a.push_back(make_pair(x,i));
	}
	sort(a.begin(),a.end());
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	vector<pair<int,int>>ans;
	int req=0,sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(a[j].first>=v[i].second.first && mark[j]==0)
			{
				mark[j]=1;
				req++;
				sum+=v[i].first;
				ans.push_back(make_pair(v[i].second.second+1,a[j].second+1));
				break;
			}
		}
	}
	cout << req << " " << sum << endl;
	sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}