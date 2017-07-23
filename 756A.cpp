#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int p[200009];
int b[200009];
bool vis[200009]={0};
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++){cin >> p[i];}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ans++;
			int x=i;
			while(!vis[x])
			{
				vis[x]=true;
				x=p[x];
			}
		}
	}
	if(ans==1){ans=0;}
	int sum=0;
	for(int i=1;i<=n;i++){cin >> b[i];if(b[i]==1){sum++;}}
	cout << ans+((sum%2)+1)%2 << endl;
	return 0;
}