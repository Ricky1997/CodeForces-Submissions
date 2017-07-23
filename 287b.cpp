#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long int n,k,lo,hi,M;
int main()
{
	cin>>n>>k;
	lo=0;hi=k-1;
	if(n>k*(k-1)/2+1)
	{
		cout << -1 << endl;
		return 0;
	}
	else
	{
		while(lo<hi)
		{
			M=(lo+hi)/2;
			if( ((2*k)-M-1)*(M)/2 + 1>=n)
				hi=M;
			else
				lo=M+1;
		}
		cout << hi << endl;
	}
	return 0;
}