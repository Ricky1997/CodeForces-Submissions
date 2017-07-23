#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int pref[100009];
int suff[100009];
int main()
{

	string x,y;
	cin >> x >> y;
	int i,j;
	pref[0]=-1;
	suff[y.length()-1]=-1;
	for(i=0;i<x.length();i++)
	{
		if(x[i]==y[0]){pref[0]=i;break;}
	}
	for(i=x.length()-1;i>=0;i--)
	{
		if(y[y.length()-1]==x[i])
		{
			suff[y.length()-1]=i;
			break;
		}
	}
	for(i=1;i<y.length();i++)
	{
		if(pref[i-1]==-1){pref[i]=-1;}
		else
		{
			int ind=pref[i-1]+1;
			pref[i]=-1;
			while(ind<x.length())
			{
				if(x[ind]==y[i])
				{
					pref[i]=ind;
					break;
				}
				ind++;
			}
		}
	}
	for(i=y.length()-2;i>=0;i--)
	{
		if(suff[i+1]==-1){suff[i]=-1;}
		else
		{
			int ind=suff[i+1]-1;
			suff[i]=-1;
			while(ind>=0)
			{
				if(x[ind]==y[i])
				{
					suff[i]=ind;
					break;
				}
				ind--;
			}
		}
	}
   /* for(i=0;i<y.length();i++)
	{
	    cout << pref[i] << " ";
	}
	cout << endl;
    for(i=0;i<y.length();i++)
	{
	    cout << suff[i] << " ";
	}*/
	int lo=0;
	int hi=y.length();
	while(lo<hi)
	{
	    //cout << lo << " " << hi << endl;
		int mid=lo+(hi-lo)/2;
		int val=0;
		for(i=0;i<=y.length()-mid;i++)
		{
			if(i!=0 && i!=y.length()-mid &&  pref[i-1]!=-1 && suff[i+mid]!=-1 && pref[i-1] < suff[i+mid] )
			{
				val=1;
				break;
			}
			if(i==0 && suff[i+mid]!=-1)
			{
				val=1;break;
			}
			if(i==y.length()-mid && pref[i-1]!=-1 )
            {
                val=1;break;
            }
		}
		if(val==1)
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	if(hi==y.length()){cout << '-' << endl; return 0;}
	string ans="";
	int mid=hi;
	for(i=0;i<=y.length()-mid;i++)
	{
			if(i!=0 && i!=y.length()-mid &&  pref[i-1]!=-1 && suff[i+mid]!=-1 && pref[i-1] < suff[i+mid] )
			{
				ans+=y.substr(0,i);
				ans+=y.substr(i+mid,y.length()-i-mid+1);
				cout << ans << endl;
				return 0;
			}
			if(i==0 && suff[i+mid]!=-1)
			{
				ans+=y.substr(i+mid,y.length()-i-mid+1);
				cout << ans << endl;
				return 0;
			}
			if(i==y.length()-mid && pref[i-1]!=-1 )
            {
                ans+=y.substr(0,y.length()-mid);
                cout << ans << endl;
                return 0;
            }
	}
}
