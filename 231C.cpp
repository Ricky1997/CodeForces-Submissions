#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int a[100009],sum[100009];
long long int n,k;
int main()
{
	cin >> n >> k;
	long long int i,j;
	for(i=0;i<n;i++){cin >> a[i];}
	sort(a,a+n);
	long long int lo=0,hi=n;
	sum[0]=a[0];
	for(i=1;i<n;i++){sum[i]=a[i]+sum[i-1];}
	long long int ans=0,ind=-1;
	while(lo<=hi)
	{
		long long int mid=lo+(hi-lo)/2;
		for(i=0;i<n;i++)
		{
			if(i+1>=mid && (a[i]*mid-(sum[i]-sum[i-mid])<=k))
			{
				ans=mid;
				ind=a[i];
				break;
			}
		}
		if(i==n)
		{
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	cout << ans << " " << ind << endl;
	return 0;
}
