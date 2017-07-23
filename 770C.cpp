#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n,k,cnt=0,val=1;
int vis[100009]={0};
int order[100009];
vector<int>ans;
vector<int> adj[100009];

void dfs(int v)
{
	if(vis[v]==1){val=-1;return;}
	else
	{
		if(vis[v]==2){return;}
		else
		{
			vis[v]=1;
			for(int i=0;i<adj[v].size();i++)
			{
				dfs(adj[v][i]);
			}
			cnt++;
			ans.push_back(v);
			vis[v]=2;
		}
	}
}

int main()
{
	int x,y;
	cin>> n >> k;
	int i,j;
	for(i=0;i<k;i++){ cin >> order[i] ;}
	for(i=1;i<=n;i++)
	{
		cin >> x;
		if(x!=0)
		{
			for(j=0;j<x;j++)
			{
				cin >> y;
				adj[i].push_back(y);
			}
		}
	}
	for(i=0;i<k;i++)
	{
		dfs(order[i]);
		if(val==-1){cout << -1 << endl; return 0;}
	}
	cout << cnt << endl;
	for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
	return 0;
}
