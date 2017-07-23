#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n,m;
vector<int>adj[100009];
int vis[100009]={0};
int dis[100009]={0};
int main()
{
	cin >> n >> m;
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	queue<int>q;
	q.push(1);
	int ver=1;
	int temp=0;
	dis[1]=0;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		vis[p]=1;
		for(int i=0;i<adj[p].size();i++)
		{
			if(vis[adj[p][i]] == 0)
			{
				vis[adj[p][i]]=1;
				q.push(adj[p][i]);
				dis[adj[p][i]]=dis[p]+1;
				if(dis[adj[p][i]] > temp){ ver = adj[p][i] ;}
			}
		}
	}
	for(int i=1;i<=n;i++){dis[i]=0;vis[i]=0;}
	queue<int>q1;
	q1.push(ver);
	temp=0;
	dis[ver]=0;
	while(!q1.empty())
	{
		int p=q1.front();
		q1.pop();
		vis[p]=1;
		for(int i=0;i<adj[p].size();i++)
		{
			if(vis[adj[p][i]] == 0)
			{
				vis[adj[p][i]]=1;
				q1.push(adj[p][i]);
				dis[adj[p][i]]=dis[p]+1;
				temp=max(temp,dis[adj[p][i]]);
			}
		}
	}
	cout << temp << endl;
	return 0;
}
