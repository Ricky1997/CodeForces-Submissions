#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int gcd(long long int a, long long int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int main()
{
	long long int a,b,x,y;
	cin >> a >>b >> x >>y;
	long long int g=gcd(x,y);
	x/=g;
	y/=g;
	if(a<x || b<y){ 	cout << 0<<" " << 0 << endl; return 0; }
	long long int m=a/x;
	long long int n=b/y;
	if(m < n)
	{
		cout << m*x <<" " << m*y << endl; return 0;
	}
	else
	{
		cout << n*x << " " <<n*y << endl; return 0;
	}
}