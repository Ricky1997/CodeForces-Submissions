#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define p 1000000007
long long int f[5009][5009]={0};
int main()
{
	string s,t;
	cin >> s >> t;
	int n=s.length();
	int m=t.length();
	int i,j;
	for(i=n-1;i>=0;i--)
	{
		for(j=m-1;j>=0;j--)
		{
			f[i][j]=f[i][j+1];
			if(s[i]==t[j])
			{
				f[i][j]+=(1+f[i+1][j+1])%p;
			}
			f[i][j]%=p;
		}
	}
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum+=f[i][0];
		sum%=p;
	}
	cout << sum%p << endl; 
	return 0;
}