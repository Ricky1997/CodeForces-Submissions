#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int m,b;
int main()
{
	cin >> m>> b;
	long long int x= m*b;
	long long int y=0;
	long long int ans=0;
	while(x>=0)
	{
		long long int t= (x+1)*(y+1)*(x+y);
		t/=2;
		ans=max(ans,t);
		x-=m;
		y++;
	}
	cout << ans << endl;
	return 0;
}
