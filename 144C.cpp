#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int a[26],b[26];
int main()
{
	string x,y;
	cin  >> x >> y;
	int n=x.length();
	int m=y.length();
	if(m>n){cout << 0 << endl; return 0;}
	int i,j,k,p,cnt=0,ans=0;
	for(i=0;i<m;i++)
	{
		a[y[i]-'a']++;
	}
	for(i=0;i<m;i++)
	{
		if(x[i]=='?'){cnt++;}
		else{b[x[i]-'a']++;}
	}
	for(i=0;i<26;i++)
	{
		if(b[i]>a[i])
		{
			break;
		}
	}
	if(i==26){ans++;}
	i=1;
	j=m-1;
	k=0;
	p=0;
	while(i<n-m+1 && j<n)
	{
		k=i-1;
		if(x[k]=='?'){cnt--;}
		else {b[x[k]-'a']--;}
		j=i+m-1;
		if(x[j]=='?'){cnt++;}
		else {b[x[j]-'a']++;}
		p=0;
		for(p=0;p<26;p++)
		{
			if(b[p]>a[p]){break;}
		}
		if(p==26){ans++;}
		i++;
	}
	cout << ans << endl;
	return 0;
}