#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n;
	string x;
	cin >> n >> x;
	vector <int> v;
	for(int i=0;i<x.length();i++)
	{
		if(x[i]=='2'){ v.push_back(2);}
		if(x[i]=='3'){v.push_back(3);}
		if(x[i]=='4'){v.push_back(2);v.push_back(2);v.push_back(3);}
		if(x[i]=='5'){v.push_back(5);}
		if(x[i]=='6'){v.push_back(3);v.push_back(5);}
		if(x[i]=='7'){v.push_back(7);}
		if(x[i]=='8'){v.push_back(2);v.push_back(2);v.push_back(2);v.push_back(7);}
		if(x[i]=='9'){v.push_back(2);v.push_back(3);v.push_back(3);v.push_back(7);}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++){ cout << v[i] ;}
	return 0;
}