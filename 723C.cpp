#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
# define ll long long int
int n,m;
ll a[2009];
ll vis[2009];
int arr[2009];
int temp[2009]={0};
int main()
{
	cin >> n >> m;
	map<ll,vector<int> > mymap;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		mymap[a[i]].push_back(i);
	}
	int b=n/m;
	int ans=0;
	int extr=0;
	int req=0;
	for(int i=0;i<2009;i++){temp[i]=b;arr[i]=0;}
	for(int i=1;i<=m;i++)
	{
		if(mymap.find(i)!=mymap.end())
		{
			if(mymap[i].size()<b)
			{
				req+=b-mymap[i].size();
			}
		}
		else
		{
			req+=b;
		}
	}
	for(std::map<ll,vector<int> > :: iterator it=mymap.begin();it!=mymap.end();it++)
	{
		if(it->first>m)
		{
			for(int i=0;i<it->second.size();i++)
			{
				arr[it->second[i]]=1;
			}
		}
		else
		{
			if(it->second.size()>=b)
			{
				for(int i=0;i<it->second.size()-b;i++)
				{
					arr[it->second[i]]=1;
				}
				temp[it->first]=0;
			}
			else
			{
				temp[it->first]=b-it->second.size();
			}
		}
	}
	ans=req;
	for(int i=1;i<=m;i++)
	{
		if(temp[i]>0)
		{
			int j=0;
			while(temp[i]!=0 && j<n)
			{
				if(arr[j]==1 && arr[j]<=temp[i])
				{
					temp[i]-=1;
					arr[j]=0;
					a[j]=i;
				}
				j++;
			}
		}
	}
	cout << b  << " " << ans << endl;
	for(int i=0;i<n;i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
