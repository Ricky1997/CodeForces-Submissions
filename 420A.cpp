#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int a[55][55];
int main()
{
	cin >> n;
	int i,j,u,v;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){cin >> a[i][j];}
	}
	int done=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			done=0;
			if(a[i][j]==1){continue;}
			for(u=0;u<n;u++)
			{
				int t=a[i][j]-a[i][u];
				for(v=0;v<n;v++)
				{
					if(a[v][j]==t){done=1;break;}
				}
			}
			if(done!=1){cout  << "No" << endl; return 0;}
		}
	}
	cout << "Yes" << endl; return 0;
}
