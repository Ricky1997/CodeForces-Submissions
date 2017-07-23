#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int h,r;
	cin >> r>> h ;
    int m=h%r;
    if(m*2>=sqrt(3)*r){ cout << h/r*2+3 << endl;}
    else if(m*2>=r){cout << h/r*2+2 << endl;}
    else{ cout << h/r*2+1 << endl;}
    return 0;
}