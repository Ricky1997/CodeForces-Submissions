#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n,m,cnt=0,ans;
vector < pair<int,int> > adj[1009][1009];
int vis[1009][1009];
int mat[1009][1009];
int dp[100009]={0};
void dfs(int i,int j)
{
	vis[i][j]=1;
	for(int u=0;u<adj[i][j].size();u++)
	{
		if(vis[adj[i][j][u].first][adj[i][j][u].second]==0)
		{
			ans++;
			mat[adj[i][j][u].first][adj[i][j][u].second]=cnt;
			vis[adj[i][j][u].first][adj[i][j][u].second]=1;
			dfs(adj[i][j][u].first,adj[i][j][u].second);
		}
	}
}
int main()
{
	cin >> n >> m;
	int i,j;
	char a[n][m]={0};
	for(i=0;i<n;i++){scanf("%s",a[i]);}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='.')
			{
				if(i+1<n && a[i+1][j]=='.' ){ adj[i][j].push_back(make_pair(i+1,j)); }
				if(i-1>=0 && a[i-1][j]=='.'){ adj[i][j].push_back(make_pair(i-1,j)); }
				if(j+1<m && a[i][j+1]=='.' ){ adj[i][j].push_back(make_pair(i,j+1)); }
				if(j-1>=0 && a[i][j-1]=='.'){ adj[i][j].push_back(make_pair(i,j-1)); }
			}
			vis[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='.' && vis[i][j]==0)
			{
					ans=1;
					cnt++;
					mat[i][j]=cnt;
					dfs(i,j);
					dp[cnt]=ans;
					//cout << cnt << " " << ans << endl;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='*')
			{
                vector<int> arr;
				if(i+1<n && a[i+1][j]=='.' ){   arr.push_back(mat[i+1][j]); }
				if(i-1>=0 && a[i-1][j]=='.'){   arr.push_back(mat[i-1][j]); }
				if(j+1<m && a[i][j+1]=='.' ){   arr.push_back(mat[i][j+1]); }
				if(j-1>=0 && a[i][j-1]=='.'){   arr.push_back(mat[i][j-1]); }
				sort(arr.begin(),arr.end());
                arr.erase(unique(arr.begin(),arr.end()),arr.end());

				int val=1;
				for(int u=0;u<arr.size();u++)
				{
					val+=dp[arr[u]];
				}
				val%=10;
				a[i][j]='0'+val;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		    printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;

}
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n,m,cnt=0,ans;
vector < pair<int,int> > adj[1009][1009];
int vis[1009][1009];
int mat[1009][1009];
int dp[100009]={0};
void dfs(int i,int j)
{
	vis[i][j]=1;
	for(int u=0;u<adj[i][j].size();u++)
	{
		if(vis[adj[i][j][u].first][adj[i][j][u].second]==0)
		{
			ans++;
			mat[adj[i][j][u].first][adj[i][j][u].second]=cnt;
			vis[adj[i][j][u].first][adj[i][j][u].second]=1;
			dfs(adj[i][j][u].first,adj[i][j][u].second);
		}
	}
}
int main()
{
	cin >> n >> m;
	int i,j;
	char a[n][m]={0};
	for(i=0;i<n;i++){scanf("%s",a[i]);}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='.')
			{
				if(i+1<n && a[i+1][j]=='.' ){ adj[i][j].push_back(make_pair(i+1,j)); }
				if(i-1>=0 && a[i-1][j]=='.'){ adj[i][j].push_back(make_pair(i-1,j)); }
				if(j+1<m && a[i][j+1]=='.' ){ adj[i][j].push_back(make_pair(i,j+1)); }
				if(j-1>=0 && a[i][j-1]=='.'){ adj[i][j].push_back(make_pair(i,j-1)); }
			}
			vis[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='.' && vis[i][j]==0)
			{
					ans=1;
					cnt++;
					mat[i][j]=cnt;
					dfs(i,j);
					dp[cnt]=ans;
					//cout << cnt << " " << ans << endl;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='*')
			{
                vector<int> arr;
				if(i+1<n && a[i+1][j]=='.' ){   arr.push_back(mat[i+1][j]); }
				if(i-1>=0 && a[i-1][j]=='.'){   arr.push_back(mat[i-1][j]); }
				if(j+1<m && a[i][j+1]=='.' ){   arr.push_back(mat[i][j+1]); }
				if(j-1>=0 && a[i][j-1]=='.'){   arr.push_back(mat[i][j-1]); }
				sort(arr.begin(),arr.end());
                arr.erase(unique(arr.begin(),arr.end()),arr.end());

				int val=1;
				for(int u=0;u<arr.size();u++)
				{
					val+=dp[arr[u]];
				}
				val%=10;
				a[i][j]='0'+val;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		    printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;

}
