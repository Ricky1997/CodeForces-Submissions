#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n,m;
int cat[100009]={0};int dp[100009]={0};int cons[100009]={0};int vis[100009]={0};
vector<int>adj[100009];
vector<int>check;
void maxcat(int v)
{
	vis[v]=1;
	int cnt=0;
	for(int i=0;i<adj[v].size();i++)
	{
		if(vis[adj[v][i]]==0)
		{
			cnt++;
			vis[adj[v][i]]=1;
			if(cat[adj[v][i]]==1){cons[adj[v][i]]=1+cons[v];}
			else{cons[adj[v][i]]=0;}
			dp[adj[v][i]]=max(cons[adj[v][i]],dp[v]);
			maxcat(adj[v][i]);
		}
	}
	if(cnt==0)
	{
		check.push_back(v);
	}
}
int main()
{
	cin >> n >> m;
	int i,j,x,y;
	for(i=1;i<=n;i++){cin >> cat[i] ;vis[i]=0;}
	for(i=0;i<n-1;i++)
	{
		cin >> x >> y ;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	if(cat[1]==1){cons[1]=1;}
	maxcat(1);
	int ans=0;
	for(int i=0;i<check.size();i++)
	{
		if(dp[check[i]]<=m){ans++;}
	}
	cout << ans << endl;
	return 0;
}
