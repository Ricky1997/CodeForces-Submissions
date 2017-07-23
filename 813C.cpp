#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,v,x,y;
	cin >> n >> v;
	int i,j;
	vector<int>adj[n+1];
	for(i=0;i<n-1;i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int disalice[n+1];
	int disbob[n+1];
	int safe[n+1];for(i=1;i<=n;i++){safe[i]=0;}
	int coloralice[n+1];for(i=1;i<=n;i++){coloralice[i]=0;}
	int colorbob[n+1];for(i=1;i<=n;i++){colorbob[i]=0;}
	disalice[1]=0;
	disbob[v]=0;
	queue<int>q;
	q.push(1);
	coloralice[1]=1;
	while(!q.empty())
	{
		int curr=q.front();
		for(i=0;i<adj[curr].size();i++)
		{
			if(coloralice[adj[curr][i]]==0){q.push(adj[curr][i]);coloralice[adj[curr][i]]=1;disalice[adj[curr][i]]=disalice[curr]+1;}
		}
		coloralice[curr]=2;
		q.pop();
	}
	queue<int>q2;
	q2.push(v);
	colorbob[v]=1;
	while(!q2.empty())
	{
		int curr=q2.front();
		for(i=0;i<adj[curr].size();i++)
		{
			if(colorbob[adj[curr][i]]==0){q2.push(adj[curr][i]);colorbob[adj[curr][i]]=1;disbob[adj[curr][i]]=disbob[curr]+1;}
		}
		colorbob[curr]=2;
		q2.pop();
	}
	for(i=1;i<=n;i++)
	{
		if(disalice[i]>disbob[i]){safe[i]=1;}
	}
	int ans=0;
	for(i=1;i<=n;i++)
	{
		if(safe[i]==1)
		{
			ans=max(ans,2*disalice[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
