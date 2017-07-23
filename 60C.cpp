#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXN  1000009
int spf[MAXN];
int arr[109][109][2];
vector<int>adj[109];
vector< int >plist[1000009];
int ans[109];
int vis[109]={0};
int tempvis[109]={0};
vector<int>num;
void sieve(){
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
    for(int x=2;x<MAXN;x++)
	{
		int y=x/spf[x];
		int cnt=0;
		for(int i=0;i<plist[y].size();i++)
		{
			if( plist[y][i]%spf[x]==0 )
			{
				cnt=1;
				plist[x].push_back(plist[y][i]*spf[x]);
			}
			else
			{
				plist[x].push_back(plist[y][i]);
			}
		}	
		if(cnt==0)
		{
			plist[x].push_back(spf[x]);
		}
		sort(plist[x].begin(),plist[x].end());
	}
}
bool dfs(int i,int val)
{
	
}
int main()
{
	
	int n,m,a,b,c,d;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		cin >> a >> b >> c >> d;
		adj[a].push_back(b);
		adj[b].push_back(a);
		arr[a][b][0]=c;
		arr[a][b][1]=d;
		arr[b][a][0]=c;
		arr[b][a][1]=d;
	}
	sieve();
	for(i=1;i<n;i++)
	{
		if(adj[i].size()!=0 && vis[i]==0)
		{
			memset(tempvis, 0, sizeof(tempvis));
			num.clear();
			int set_size=plist[i].size();
			unsigned int pow_set_size = pow(2, set_size);
	   		int counter, j;
    		for(counter = 0; counter < pow_set_size; counter++)
    		{
    			int cur=1;
      			for(j = 0; j < set_size; j++)
      			{	
          			if(counter & (1<<j))
            			cur*= plist[i][j];
       			}
      			if(cur!=1){num.push_back(cur);}
    		}
    		int cnt=0;
    		for(j=0;j<num.size();j++)
    		{
    			if(dfs(i,num[j])==1)
    			{
    				break;
    				cnt=1;
    			}
    		}
    		if(cnt==0)
    		{
    			cout << "NO" << endl; return 0;
    		}
    		else
    		{

    		}
		}
	}



}