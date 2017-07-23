#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int r,b,g,ans,a[3]; 

int main()
{
    cin >> r >> b >> g ;
	a[0]=r;
	a[1]=b;
	a[2]=g;
	sort(a,a+3);
 	cout << min( (a[0]+a[1]+a[2])/3, a[0] + a[1]) << endl;
	return 0;
}