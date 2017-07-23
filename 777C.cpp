#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,m,t,l,r;
	cin >> n >> m;
	int a[n][m],dp[n][m], fn[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>> a[i][j];
		}
	}
	fn[n-1]=1;
	for(int i=0;i<m;i++){dp[n-1][i]=1;}
	for(int i=n-2;i>=0;i--)
	{
		fn[i]=1;
		for(int j=0;j<m;j++)
		{
			if(a[i][j]<=a[i+1][j])
			{
				dp[i][j]=1+dp[i+1][j];
			}
			else
            {
             dp[i][j]=1;
            }
            fn[i]=max(fn[i],dp[i][j]);
		}
	}
	cin >> t;
	while(t--)
	{
		cin >> l >> r;
		if(l-1+fn[l-1]>=r){cout << "Yes" << endl;}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;}
