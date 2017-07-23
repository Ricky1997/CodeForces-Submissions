#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
bool prime[1000009];
int primet[1000009];
void seive()
{
	int n=1000009;
    memset(prime,true,sizeof(prime));
	prime[0]=0;
	prime[1]=0;
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    primet[0]=0;
    primet[1]=0;
    for(int i=2;i<=n;i++)
    {
    	primet[i]=primet[i-1];
    	if(prime[i])
    	{
    		primet[i]++;
    	}
    }
}
int main()
{
	int a,b,k;
	cin >> a >> b >> k;
	seive();
	int lo=1;
	int hi=b-a+1;
	int cnt=0;
	//for(int i=0;i<20;i++){cout <<prime[i] << " "<<  primet[i] << endl;}
	while(lo<=hi)
	{
		int mid= lo+(hi-lo)/2;
		int x=a;
		for(x=a;x<=b-mid+1;x++)
		{
			if(primet[x+mid-1]-primet[x-1]<k)
			{
				break;
			}
		}
		if(x == b-mid+2){hi=mid-1;cnt++;}
		else{lo=mid+1;}
	}
	if(cnt==0){cout << -1 << endl;}
	else {cout << lo << endl;}
	return 0;
}
