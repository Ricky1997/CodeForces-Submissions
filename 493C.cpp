#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n,m;
long long int a[200009],b[200009];
int main()
{
	cin >> n ;
	int i,j;
	for(i=0;i<n;i++){cin >> a[i];}
	cin >> m;
	for(i=0;i<m;i++){cin >> b[i];}
	sort(a,a+n);
	sort(b,b+m);
	int p=0,q=0;
	int x=0;
	for(i=0;i<m;i++)
	{
		x=upper_bound(a,a+n,b[i])-a;
		x--;
		if(i-x > q-p)
		{
			q=i+1;
			p=x+1;
		}
	}
	int s1= 2*p + 3*(n-p);
	int s2= 2*q + 3*(m-q);
	cout << s1 <<":" << s2 <<endl;
	return 0;
}