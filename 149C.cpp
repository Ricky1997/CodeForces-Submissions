#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
double n;
long long int a[100009];
int main()
{
	cin >> n ;
	int i;
	vector<pair<int,int>>v;
	for(i=1;i<=n;i++)
	{	
		cin >> a[i];
		v.push_back(make_pair(a[i],i));
	}
	sort(v.begin(),v.end());
	int x= ceil(n/2);
	int y= floor(n/2);
	cout << x << endl;
	for(i=0;i<n;i+=2)
	{
		cout << v[i].second << " " ;
	}
	cout << endl << y << endl;
	for(i=1;i<n;i+=2)
	{
		cout << v[i].second << " " ;
	}
	return 0;
}