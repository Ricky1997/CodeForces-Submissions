#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int n,p;
long long int d[100009],h[100009];
int main()
{
	cin >> n >> p;
	int i,j,cnt=0;
	cin >> d[0] >> h[0];
	for(i=1;i<p;i++)
	{
		cin >> d[i] >> h[i];
		if(d[i]-d[i-1] <abs(h[i]-h[i-1])){cnt=1;}
	}
	if(cnt==1){cout << "IMPOSSIBLE" << endl; return 0;}
	else
	{
		long long int m=h[0]+d[0]-1;
		m=max(m,n-d[p-1]+h[p-1]);
		long long int x=0;
		for(i=1;i<p;i++)
		{
			x= h[i]+h[i-1] + d[i]-d[i-1];
			x=x/2;
			//cout << x << endl;
			m=max(m,max(h[i],max(h[i-1],x)));
		}
		cout << m << endl;
		return 0;
	}
}