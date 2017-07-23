#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int a[10001],b[10003];
int main()
{
	int n,m,x,y,z,i,j,ans=0;
	cin >> n>> m;
	b[0]=0;
	for(i=0;i<n;i++){cin >> a[i];b[i+1]=0;}
	vector <int> v;
	for(i=0;i<m;i++)
	{
		cin >> x >> y >> z;
		for(j=x;j<=y;j++)
		{
			b[a[j-1]]=1;
		}
		int p=z-x+1;
		for(j=1;j<=n;j++)
		{
			if(b[j]>0 && b[j]<p)
			{
				p-=1;
			}
			else if(b[j]>0 && b[j]>=p)
			{
				ans=j;
				break;
			}
		}
		if(ans==a[z-1]){ cout << "Yes" <<endl;}
		else{cout << "No" << endl;}
		for(j=x;j<=y;j++)
		{
			b[a[j-1]]=0;
		}
		ans=0;
	}
	return 0;
}
