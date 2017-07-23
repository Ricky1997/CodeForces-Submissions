#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	int a[n],b[k];
	int i,j;
	int cnt=0;
	for(i=0;i<n;i++){cin >> a[i];if(a[i]==0){cnt++;}}
	for(i=0;i<k;i++){cin >> b[i];}
	sort(b,b+k);
	reverse(b,b+k);
	if(cnt>k){cout << "No" << endl; return 0;}
	else
	{
		i=0;
		j=0;
		while(i<n && j<k)
		{
			if(a[i]==0){a[i]=b[j];j++;}
			i++;
		}
	}
	for(i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1]){cout << "Yes" << endl; return 0;}
	}
	cout << "No" << endl;
	return 0;
}
