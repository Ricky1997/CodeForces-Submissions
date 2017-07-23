#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
# define ll long long
# define N 100000
ll x,y,w;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int rev(int x)
{
	string y="";
	y+='0';
	while(x!=0)
	{
        y+= '0'+x%10;
		x=x/10;
	}
	int u=stoi(y);
	return u;
}
int main()
{
	cin >> x >> y >> w;
	ll lo1=1,hi1=x*y;
	ll a1=N,a2=N;
	while(lo1<=hi1)
	{
		ll mid1= (lo1+(hi1-lo1)/2);
		//cout << lo1 << " " << hi1 << endl;
		int upd=0;
		for(ll i=1;i*i<=mid1;i++)
		{
		    //cout << "y" << endl;
			if(mid1%i==0 && i<=x && mid1/i <=y)
			{
				int u=i,v=mid1/i;

			    //cout << u << " " << v << endl;
				map< pair<int,int>,int > m1;
				for(int j=1;j<=u;j++)
				{
					int u=rev(j);
					int z=gcd(j,u);
					m1[make_pair(j/z , u/z)]++;
				}
				map< pair<int,int>,int > m2;
				for(int j=1;j<=v;j++)
				{
					int u=rev(j);
					int z=gcd(j,u);
					m2[make_pair(u/z , j/z)]++;
				}
				ll val=0;
				for(std:: map< pair<int,int>,int > :: iterator it=m1.begin();it!=m1.end();it++)
				{
					if(m2.find(it->first)!=m2.end())
					{
						val+=(it->second * m2[it->first]);
					}
				}
				if(val>=w)
				{
					upd=1;
					    a1=u;
				    	a2=v;

				}
			}
		}
		if(upd==0)
		{
			lo1=mid1+1;
		}
		else
		{
			hi1=mid1-1;
		}
	}
	if(a1==N && a2==N)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << a1 << " " << a2 << endl;
	}
	return  0;
}
