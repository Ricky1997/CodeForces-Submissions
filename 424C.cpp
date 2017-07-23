#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int f[1000009];
int n,a[1000009];
int main()
{
	cin >> n;
	int i,k;
	long long int x=0,q=0;
	for(i=0;i<n;i++){cin >> a[i];x=x^a[i];}
	f[0]=0;
	for(i=1;i<=n;i++){f[i]=f[i-1]^i;}
	for(k=1;k<=n;k++)
	{
		long long int p=n/k;
		p=p%2;
		if(p==0)
		{
			x=x^f[n%k];
		}
		else
		{
			x=x^f[k-1];
			x=x^f[n%k];
		}
	}
	cout << x << endl;
	return 0;
}
