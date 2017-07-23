#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
int gcd(int a,int b)
{
	
}
int main()
{
	long long int t,x,y,p,q,a,b,c;
	cin>> t;
	while(t)
	{
		 cin >> x >> y >> p >> q ;
		 c = q*x - p*y;
		 a=p;
		 b=p-q;
		 int f,s,gcd;
		 gcd=gcdExtended(a,b,&f,&s);
		 if(c%gcd!=0){cout << -1 << endl; t--; continue;}
		 else
		 {
		 	int t=f/( b/gcd );
		 	if( f - (b*t)/gcd < 0)
		 	{
		 		t++;
		 		if( f - (b*t)/gcd < 0)
		 		{
		 			t-=2;
		 		}	
		 	}
		 	int u=(-s)/( a/gcd );
		 	if((a*t)/gcd+s < 0)
		 	{
		 		u++;
		 		if( (a*t)/gcd +s < 0)
		 		{
		 			u-=2;
		 		}	
		 	}
		 	int ans=0;
		 	if(t<u)
		 	{
		 	 	f-(b*t)/gcd	+ 
		 	}
		 	else
		 	{

		 	}
		 }
	}

}