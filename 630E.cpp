#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long int p,r,q,s,a,b,e,t,ans;

int main()
{
	cin >> p >> r >> q >> s;
	b= ((s-r)/2) + 1;
	a=b;
	if(r%2==0 && s%2==0){b-=1;}
	if(r%2!=0 && s%2!=0){a-=1;}
	t=q-p +1;
	e= ((q-p)/2) +1;
	if(p%2!=0 && q%2!=0){e-=1;}
	ans = a*e + b*(t-e);
	cout << ans << endl;
	return 0;
}