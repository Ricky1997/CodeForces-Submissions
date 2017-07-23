#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	long double a,b;
	cin >> a >> b;
	long long int x=a;
	long long int y=b;
	long double p= sqrt(a);
	p=(int)p;
	if(b - p*(p+1) >=0){cout << "Vladik" << endl; return 0;}
	else{cout << "Valera" << endl; return 0;}
	return 0;
}
