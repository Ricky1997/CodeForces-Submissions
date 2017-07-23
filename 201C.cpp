#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int x;
	cin >> x;
	if(x==1){cout << 1 << endl; return 0;}
	if(x==3){cout << 5 << endl; return 0;}
	x=2*x - 1;
	for(int i=3;i<=15;i+=2)
	{
		if(x> ((i-2)*(i-2)) && x<= i*i )
		{
			cout << i << endl; 
			return 0;
		} 
	}
}