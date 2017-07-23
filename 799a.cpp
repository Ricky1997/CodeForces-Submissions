#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,t,k,d,a;
	cin >>n >>t >>k >>d;
	a= ceil(n/k)*t -1;
	if(n< (a/t)*k + ( (a-d)/t )*k){ cout << "YES" << endl;}
	cout << "NO" << endl;
	return 0;
}