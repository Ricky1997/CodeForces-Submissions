#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
# define MAXN 5000001
long int spf[MAXN];
long int dp[MAXN];
void sieve()
{
    spf[1] = 1;
    for (long int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (long int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (long int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (long int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
int main()
{
	long int t,a,b,ans;
	cin >> t;
	sieve();
	dp[0]=0;dp[1]=0;dp[2]=1;dp[3]=2;
	for(long int i=4;i<MAXN;i++)
	{
		dp[i]=dp[i-1] + dp[i/spf[i]]-dp[(i/spf[i])-1]+1;
	}
	while(t>0)
	{
		scanf("%ld",&a);
		scanf("%ld",&b);
		ans=dp[a]-dp[b] ;
		printf("%ld\n",ans);
		t--;
	}
	return 0;
}
