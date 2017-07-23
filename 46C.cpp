#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n;
	string x;
	cin >> n;
	cin >> x;
	int h=0;
	int t=0;
	for(int i=0;i<n;i++)
	{
		if(x[i]=='H'){h++;}
		else{t++;}
	}
//	cout << h << " " << t << endl;
	int ans=INT_MAX;
	for(int i=0;i<n;i++)
	{
		char a[n];
		int u=h,v=t,k=i,val=0;
		while(u!=0)
		{
			a[k]='H';
			k++;
			k%=n;
			u--;
		}
		while(v!=0)
		{
			a[k]='T';
			k++;
			k%=n;
			v--;
		}
		for(int j=0;j<n;j++)
		{
			//cout << a[j] << " " << x[j] << endl;
			if(a[j]!=x[j]){val++;}
		}
		ans=min(ans,val/2);
	}
	cout << ans << endl;
	return 0;
}
