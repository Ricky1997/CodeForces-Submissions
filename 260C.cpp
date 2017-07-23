#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n,k;
long long int a[100009],b[100009];
int main()
{
	cin >> n >> k;
	long long int i,j,cnt=0;
	long long int mi=INT_MAX;
	for(i=1;i<=n;i++){cin >> a[i] ; mi=min(mi,a[i]);}
	j=k;	
	while(1)
	{	
		if(a[j]==mi){break;}
		else
		{
			if(j==1){j=n;}
			else{j--;}
		}
	}
	i=j;
	while(i!=k)
	{
		if(i==n+1){i=1;continue;}
		else if(i!=j)
		{
			a[i]--;
			cnt++;
			i++;
		}
		else if(i==j){i++;}
	}
	if(j!=k){a[k]--;cnt++;}
	for(i=1;i<=n;i++)
	{
		if(i!=j){	a[i]-=a[j];	}
	}
	a[j]*=n;
	a[j]+=cnt;
	for(i=1;i<=n;i++){cout << a[i] << " " ;}
	return 0;
}