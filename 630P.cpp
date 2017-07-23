#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define PI 3.14159265359 

int main()
{
	long double i,n,r,ans;
	cin >> n >> r;
	ans=  (n*(r*r)/2)*( sin(2*PI/n) - 2*( (sin(PI/n)*sin((PI)/n))/tan(3*PI/(2*n) ) ) ) ;
	cout <<setprecision(15)<< ans <<  endl;
}