#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int op[12345],ep[12345];
int main()
{
    int n,m;
	cin >> n ;
	int a[n];
	cin >> a[0];
	m=a[0];
	for(int i=1;i<n;i++){ cin >> a[i];m = max(abs(a[i]),abs(m));}
	long long int sum=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>0){sum+=a[i];}
	 	if(a[i]%2!=0)
	 	{
	 		if(abs(a[i])<=abs(m))
	 		{
	 			m=abs(a[i]);
	 		}
	 	}
	}
	if(sum%2==0){sum=sum-m;}
	cout << sum << endl;
}