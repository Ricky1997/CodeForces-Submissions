#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	int n,k;
	cin >> n>> k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	map <string,int> m;
	for(int i=0;i<k;i++)
	{
		string x;
		cin >> x;
		m[x]++;
	}
	sort(a,a+n);
	std::map<string,int>::iterator it = m.begin();
	vector <int> v;
	for(it;it!=m.end();it++)
	{
		v.push_back(it->second);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int g=v.size();
	int ans=0;
	for(int i=0;i<g;i++)
	{
		ans+= a[i]*v[i];
	}
	cout << ans << " ";
	 ans=0;
	reverse(a,a+n);
	for(int i=0;i<g;i++)
	{
		ans+= a[i]*v[i];
	}
	cout << ans << endl;
	return 0;

}