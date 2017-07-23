#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int a[100009];

int main()
{
	int n,i,j;
	cin >> n;
	vector<int>v[33];
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		for(j=0;j<30;j++)
		{
			if(a[i]>>j & (1) == 1 )
			{
				v[j+1].push_back(a[i]);
			}
		}
	}
	vector<int>ans;
	for(i=29;i>=1;i--)
	{
		int andt=pow(2,30)-1;
		for(j=0;j<v[i].size();j++)
		{
			andt&=v[i][j];
		}
		if(andt % 1<<(i-1)==0)
		{
			cout << v[i].size();
			for(j=0;j<v[i].size();j++)
			{
				cout<< v[i][j] << " ";
			}
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}