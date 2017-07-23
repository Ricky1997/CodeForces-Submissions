#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,m,k;
	cin >> n>> m >> k;
	string a[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	vector< pair<int,int> >adj[n][m];
	int vis[n][m];
	int ind1;
	int ind2;
	int s=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='.')
			{
				s++;
				ind1=i;
				ind2=j;
				if(i+1<n && a[i+1][j]=='.'){adj[i][j].push_back(make_pair(i+1,j));}
				if(i-1>=0 && a[i-1][j]=='.'){adj[i][j].push_back(make_pair(i-1,j));}
				if(j+1<m && a[i][j+1]=='.'){adj[i][j].push_back(make_pair(i,j+1));}
				if(j-1>=0 && a[i][j-1]=='.'){adj[i][j].push_back(make_pair(i,j-1));}
			}
			vis[i][j]=0;
		}
	}
	i=ind1;
	j=ind2;
	queue< pair<int,int> > q;
	q.push(make_pair(i,j));
	k=s-k;
	//cout << i << " " << j << " " << k << endl;
	while(!q.empty() && k>0)
	{
		i=q.front().first;
		j=q.front().second;
		q.pop();
		vis[i][j]=1;
		a[i][j]='p';
		k--;
		for(int u=0;u<adj[i][j].size();u++)
		{
			if(vis[adj[i][j][u].first][adj[i][j][u].second]==0)
			{
			    vis[adj[i][j][u].first][adj[i][j][u].second]=1;
				q.push(adj[i][j][u]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='.'){a[i][j]='X';}
		}
	}
    for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='p'){a[i][j]='.';}
		}
	}
	for(i=0;i<n;i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}
