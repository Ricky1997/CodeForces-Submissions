#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int dp[300009];
#define p 1000000007
long long int power(long long int x,long long int y)
{
    long long int res = 1;     
    x = x % p; 
    while (y > 0)
    {

        if (y & 1)
           { res = (res*x) % p;}

        y = y>>1; 
        x = (x*x) % p;  
    }
    return res;
}
int main()
{
	int n;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	dp[0]=0;
	long long int sum=0;
	for(int i=0;i<n-1;i++)
	{
		dp[i+1]=( (2*dp[i])%p + ( ((a[i+1]-a[i])%p)*(power(2,i+1)-1))%p )%p;
		sum+=dp[i+1];
		sum=sum%p;
	}
	cout << sum%p << endl;
	return 0;
}
