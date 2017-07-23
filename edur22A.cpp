#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int a[10009],b[20009],vis[20009]={0};
int n,m;
int main()
{
	cin >>n;
	a[0]=0;
	for(int i=0;i<n;i++){cin >> a[i];}
	sort(a,a+n);
	int i,j=0;
	for(i=1;i<n;i++){a[i]+=a[i-1];}
	cin >> m;
	for(i=0;i<m;i++)
	{
		cin >> b[j] >> b[j+1];
		j+=2;
	}
	for(i=0;i<n;i++)
	{
		
	}





	return 0;
}