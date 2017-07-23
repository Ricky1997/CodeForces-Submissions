#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
# define N 10000001
int m,n,a[100009],dp[100009],f[100009];
int main()
{
	cin >> n >> m;
	int i,j;
	for(i=0;i<n;i++){cin >> a[i];}
	j=1;
	i=0;
	while(a[j]>=a[i])
	{	i++;j++;}
	while(a[j]<=a[i])
	{	i++;j++;	}
	dp[0]=min(i,n-1);
	dp[n-1]=n-1;
	i=0;
	j=1;
	while(a[j]==a[i])
	{	i++;j++;}
	f[0]=i;
	f[n-1]=n-1;
	for(i=0;i<n-2;i++)
	{
	    if(f[i]>i+1)
	    {
	        f[i+1]=f[i];
	    }
	    else
	    {
	        int k=i+1;
	        j=i+2;
	        while(j<n && k<n-1 && a[j]==a[k])
	        {	k++;j++;}
	        f[i+1]=k;
	    }
	}
	for(i=0;i<n-2;i++)
	{
		if(dp[i]>i+1)
		{
			if(f[i+1]==dp[i])
			{
			    int k=f[i+1];
		    	j=k+1;
			    while(k<n-1 && j <n && a[j]>=a[k])
		    	{	k++;j++;}
		    	while(k<n-1 && j <n && a[j]<=a[k])
		    	{	k++;j++;}
			    dp[i+1]=k;
			}
			else
			{
			    dp[i+1]=dp[i];
			}
		}
		else
		{
			int k=i+1;
			j=i+2;
			while(k<n-1 && j <n && a[j]>=a[k])
			{	k++;j++;}
			while(k<n-1 && j <n && a[j]<=a[k])
			{	k++;j++;}
			dp[i+1]=k;
		}
	}
	int x,y;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		if( y-1 <= dp[x-1] ){printf("Yes\n");}
		else{printf("No\n");}
	}
	return 0;
}