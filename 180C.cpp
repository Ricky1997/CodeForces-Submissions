#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	string A;
	cin >> A;
	int n=A.length();
	int sumu[n];
	int suml[n];
	if(A[0]-'A'<=25 && A[0]-'A'>=0){sumu[0]=1;suml[0]=0;}
	else{suml[0]=1;sumu[0]=0;}
	int i,j;
	for(i=1;i<n;i++)
	{
		if(A[i]-'A'<=25 && A[i]-'A'>=0){sumu[i]=1+sumu[i-1];suml[i]=suml[i-1];}
		else{suml[i]=1+suml[i-1];sumu[i]=sumu[i-1];}
	}
	if(suml[n-1]==n || sumu[n-1]==n){cout << 0 << endl;return 0;}
	int ans=sumu[n-1];
	for(i=0;i<n;i++)
	{
		ans=min(ans,i+1+sumu[n-1]-(2*sumu[i]));
	}
	cout << ans << endl;
	return 0;
}