#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int a[100009],b[100009],cost[100009],ind[100009],M[100009],I[100009];
int main()
{
int n;
cin >> n;
int i,j;
for(i=0;i<n;i++){cin >> a[i];}
for(i=0;i<n;i++){cin >> b[i];}
cost[1]=b[0]*a[n-1];
ind[1]=0;
M[n-2]=b[n-2]*a[n-1];
I[n-2]=n-2;
for(i=n-3;i>=0;i--)
{
	if(b[i]*a[i+1] + b[i+1]*a[n-1]<=b[i]*a[I[i+1]] + b[I[i+1]]*a[n-1])
	{
		M[i]=b[i]*a[i+1] + b[i+1]*a[n-1];
		I[i]=i+1;
	}
	else
	{
		M[i]=b[i]*a[I[i+1]] + b[I[i+1]]*a[n-1];
		I[i]=I[i+1];
	}
}
long long int ans=cost[1];
for(i=2;i<n;i++)
{
	cost[i]+=M[ind[i]]-b[ind[i]]*a[n-1];
	ans=min(ans,cost[i]);
}
cout << ans << endl;
}