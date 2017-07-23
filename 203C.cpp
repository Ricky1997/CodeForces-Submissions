#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int n,d;
long long int sum[100009];
int main()
{
	cin >> n>> d;
	long long int a,b;
	cin >> a >> b;
	vector < pair<long long int,long long int> > v;
	long long int x,y;
	int i;
	for(i=1;i<=n;i++)
	{
		cin >> x >> y;
		v.push_back(make_pair((a*x + b*y),i));
	}
	sort(v.begin(),v.end());
	i=0;
	sum[0]=v[0].first;
	for(i=1;i<n;i++)
	{
		sum[i]=v[i].first+sum[i-1];
	}
	int ind=upper_bound(sum,sum+n,d)-sum;
	cout << ind << endl;
	for(i=0;i<ind;i++)
	{
		cout << v[i].second << " ";
	}
	return 0;
}