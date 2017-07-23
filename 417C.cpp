#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int n,s;
long long int a[100009],b[100009];
int main()
{
	cin >> n>> s;
	int i,j;
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		cin >> a[i];
		b[i]=a[i];
	}
	long long int lo=0,hi=n;
	long long int k=0;
	vector< pair<long long int,long long int> >v;

	while(lo<=hi)
	{
		k=lo+(hi-lo)/2;
		for(i=1;i<=n;i++){a[i]+=i*k;}
		sort(a+1,a+n+1);
		long long int sum=0;
		for(i=1;i<=k;i++){sum+=a[i];}
		if(sum>s){hi=k-1;}
		else
		{
			v.push_back(make_pair(k,sum));
			lo=k+1;
		}
		for(i=1;i<=n;i++){a[i]=b[i];}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	if(v.size()==0){cout <<  0 << " " << 0 << endl; return 0;}
	long long int ans1=v[0].first;
	i=0;
	long long int ans2=INT_MAX;
	while(v[i].first==ans1)
	{
		ans2=min(ans2,v[i].second);
		i++;
	}
	cout <<  ans1 << " " << ans2 << endl;
	return 0;
}
