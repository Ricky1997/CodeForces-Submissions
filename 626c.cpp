#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int n,m,i;

int main()
{
    cin >> n >> m;
	for(i=1;;i++)
	{
		if(n<=i/2 && m<=i/3 && n+m<=i/2+i/3-i/6)
			break;
	}
	cout << i << endl;
	return 0;
}