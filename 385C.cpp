#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
# define N 10000001
int a[10000009],SPF[10000009],f[10000009],g[10000009];
vector< bool >isprime(10000009, true);
vector<int>prime;
void manipulated_seive()
{
    isprime[0] = isprime[1] = false ;
    for (int i=2; i<N ; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (int j=0;j < (int)prime.size() && i*prime[j] < N && prime[j] <= SPF[i]; j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}
void fn(int x)
{
    int curr = SPF[x];    
    while (x > 1)
    {
        x /= SPF[x];
        if (curr == SPF[x])
        {
            continue;
        }
 		f[curr]++;
        curr = SPF[x];
    }
}

int main()
{
    int n,m;
	scanf("%d",&n);
	manipulated_seive();
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		fn(a[i]);
	}
	scanf("%d",&m);
	int l,r;
	g[0]=0;
	g[1]=0;
	for(i=2;i<10000001;i++)
	{
		g[i]=g[i-1]+f[i];
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&l,&r);
		l=min(l,10000000);
		r=min(r,10000000);
		printf("%d\n",g[r]-g[l-1]); 
	}
	return 0;
}