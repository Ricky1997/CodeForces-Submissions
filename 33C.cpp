#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int a[100009],sums[100009],sump[100009],f[100009];
int main()
{
	cin >> n;
	int i;
	for(i=0;i<n;i++){cin >> a[i];}
	sump[0]=a[0];
	for(i=1;i<n;i++){sump[i]=a[i]+sump[i-1];}
	sums[n-1]=a[n-1];
	for(i=n-2;i>=0;i--){sums[i]=a[i]+sums[i+1];}
	f[n-1]=max(a[n-1],-a[n-1]);
	for(i=n-2;i>=0;i--){ f[i]=max(a[i]+f[i+1],-sums[i]);}
	int ans=f[0];
	ans=max(ans,-sump[n-1]);
	for(i=0;i<n-1;i++)
	{
		ans=max(ans,f[i+1]-sump[i]);
	}
	cout << ans << endl; return 0;
}