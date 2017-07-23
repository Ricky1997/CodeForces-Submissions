#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,k,i;
	scanf("%d",&n);
	scanf("%d",&k);
	long double a[n],b[n],sum=0,val;
	cin >> a[0];
	b[0]=a[0];
	for( i=1;i<n;i++){cin >> a[i]; b[i]=b[i-1]+a[i];}
	sum+=b[k-1];
	for( i=1;i<n-k+1;i++)
	{
		sum+=b[k+i-1]-b[i-1];
	}
	val = (long double)(n-k+1);
	sum=sum/val;
	cout << setprecision(15) << sum << endl;
	return 0;	
}