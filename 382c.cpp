#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
# define p 1000000007
int main()
{
	int n;
	cin >> n;
	if(n==1){cout << -1 << endl; return 0;}
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	int ans=0;
	if(n==2)
	{ 
		ans+=2;
		if(a[0]==a[1]){ cout << 1 <<endl; return 0;}
		if((a[0] != a[1]) && (a[0]+a[1])%2==0)
		{ans+=1;};
		cout << ans << endl; return 0;
	}
	map<int,int> d;
	int d1=-1,d2=-1,d3=-1;
	for(i=1;i<n;i++)
	{
		d[a[i]-a[i-1]]++;
	}
	if(d.size()>=3){cout<<0<<endl; return 0;}
	if(d.size()==1){ if(d.begin()->first == 0){cout << } }