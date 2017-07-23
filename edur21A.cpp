#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int n,temp;
long long int power(long long int x,long long int y)
{
    long long int res = 1;      // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) ;
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) ;  
    }
    return res;
}
int main()
{
	cin >>n ;
	temp=n;
	int count=0;
	while(temp>9)
	{
	    count++;
		temp/=10;
	}
	temp+=1;
    cout << temp*(power(10,count))-n << endl;
	
	return 0;
}