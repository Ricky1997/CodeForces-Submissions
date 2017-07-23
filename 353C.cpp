#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int a[100009];
long long int sum[100009],f[100009];
int main()
{
	int i,j;
	string m;
	cin >> n >> a[0];
	sum[0]=a[0];
	for(i=1;i<n;i++){cin >> a[i];sum[i]=a[i]+sum[i-1];}
	cin >> m;
	int x=m.length()-1;
	while(x>=0)
	{
		if(m[x]=='0'){x--;}
		else{break;}
	}
	string y;
	if(x==-1){cout << 0 << endl; return 0;}
	y=m.substr(0,x+1);
	reverse(y.begin(),y.end());
	x=y.length();
	f[0]=0;
	if(y[0]=='1'){f[0]=a[x-1];}
	for(i=1;i<x;i++)
	{
		if(y[i]=='1'){f[i]=a[x-i-1]+f[i-1];}
		else{f[i]=f[i-1];}
	}
	long long int ma=f[x-1];
	for(i=0;i<x-1;i++)
	{
		if(y[i]=='1')
		{
			long long int w;
			if(i>=1){w=f[i-1]+sum[x-i-2];}
			else{w=sum[x-i-2];}
			ma=max(ma,w);
		}
	}
	cout << ma << endl;
	return 0;
}
