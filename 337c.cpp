#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int n,m,k,ans,t;
#define p 1000000009
long long int power(long long int x,long long int y, long long int d)
{
    long long int res = 1;      // Initialize result

    x = x % d;  // Update x if it is more than or 
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % d;
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % d;  
    }
    return res;
}

int main()
{
	cin >> n >> m >> k;
	long long int a = (n%k) + (n/k)*(k-1);
	//cout << a << endl;
	if(m <= a){ ans = m;}
	else
	{
		t=m-a;
		ans=((((power(2,t+1,p)- 2)%p)*k)%p + ((((n/k)%p - t%p )*(k-1))%p + n%k)%p );
	}
	while(ans%p < 0 )
	{
		ans=(ans+p)%p;
	}
	cout << ans%p << endl;
    return 0;
}