#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int ans[1009]={0};
int cnt[1009]={0};
int main()
{
	int n,i,j;
	cin >> n;
	int a[n],b[n];
	for(i=0;i<n;i++){cin >> a[i];}
	for(i=0;i<n;i++){cin >> b[i];}
		int ind1=-1,ind2=-1;
	for(i=0;i<n;i++)
	{
		if(a[i]==b[i]){ans[i]=a[i];cnt[a[i]]=1;}
		else
		{
			if(ind1==-1){ind1=i; continue;}
			else
			{
				ind2=i; continue;
			}
		}
	}
	int arr[3];
	j=0;
	for(i=1;i<=n;i++)
	{
		if(cnt[i]==0){arr[j]=i;j++;}
	}
	if(j==0)
	{
		for(i=0;i<n;i++){cout << ans[i] << " " ;}
		return 0;
	}
	else if(j==1)
	{
		ans[ind1]=arr[0];
		for(i=0;i<n;i++){cout << ans[i] << " " ;}
		return 0;
	}
	else if(j==2)
	{
		ans[ind1]=arr[0];
		ans[ind2]=arr[1];
		if( (a[ind1]!=ans[ind1] && a[ind2] !=ans[ind2]) || (b[ind1]!=ans[ind1] && b[ind2] !=ans[ind2]))
		{
			ans[ind1]=arr[1];
			ans[ind2]=arr[0];
		}
		for(i=0;i<n;i++){cout << ans[i] << " " ;}
		return 0;
	}

	return 0;
}
