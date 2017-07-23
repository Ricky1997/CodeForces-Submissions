#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
vector<int>adj[1000009];
int vis[1000009]={0};
int dis[1000009]={0};
int main()
{
	int n;
	cin >> n;
	int i,x,y,z;
	int cnt=n;
	for(i=0;i<n-1;i++)
	{
		cin >> x >> y >> z;
		if(z==1){adj[x].push_back(y);adj[y].push_back(x);}
		else
		{
			adj[x].push_back(cnt);
			adj[cnt].push_back(x);
			z--;
			while(z>1)
			{
				adj[cnt].push_back(cnt+1);
				adj[cnt+1].push_back(cnt);
				cnt++;
				z--;
			}
			adj[cnt].push_back(y);
			adj[y].push_back(cnt);
			cnt++;
		}
	}
	queue<int>q;
	q.push(0);
	dis[0]=0;
	int ans=0;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		vis[curr]=1;
		for(i=0;i<adj[curr].size();i++)
		{
			if(vis[adj[curr][i]]==0)
			{
				q.push(adj[curr][i]);
				dis[adj[curr][i]]=dis[curr]+1;
				ans=max(ans,dis[curr]+1);
				vis[adj[curr][i]]=1;
			}
		}
	}
	cout << ans << endl;
    return 0;
}
