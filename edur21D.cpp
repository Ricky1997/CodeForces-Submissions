#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int a[111111],s[111111],u[11111],t;
bool cmp2(const pair<int,int> &p1, const int v)
{
    if(p1.first<v)
        return true;
    else
        return false;
}
int main()
{
	int n,i;
	cin >> n;
	cin >> a[0];
	s[0]=a[0];
	vector< pair <int,int> > v;
	v.push_back(make_pair(a[0],0));
	for(i=1;i<n;i++){cin >>a[i];v.push_back(make_pair(a[i],i));s[i]=s[i-1]+a[i];}
	t=s[n-1];
    if(t%2!=0){cout << "NO" << endl; return 0;}
    stable_sort(v.begin(),v.end());
    long long int x,ind;
    for(i=0;i<n;i++)
    {
        x=t/2-s[i]+a[i];
        ind=lower_bound(v.begin(), v.end(),x,cmp2)-v.begin();
        if(ind==v.end()-v.begin()){continue;}
        else if( v[ind].first!=x){continue;}
        else
        {
            while(v[ind].first==x)
            {
                ind++;
                if(ind==v.end()-v.begin())
                {
                   ind--;
                   break;
                }
            }
            if(ind!=v.end()-v.begin()-1){ind--;}
        	if(v[ind].second >= i){ cout << "YES" << endl; return 0;}
        }
    }
    u[n-1]=a[n-1];
    for(i=n-2;i>=0;i--){ u[i]=u[i+1]+a[i];}
    for(i=n-1;i>=0;i--)
    {
        x=t/2-u[i]+a[i];
        ind=lower_bound(v.begin(), v.end(),x,cmp2)-v.begin();
        if(ind==v.end()-v.begin()){continue;}
        else if( v[ind].first!=x){continue;}
        else
        {
        	if(v[ind].second <= i){ cout << "YES" << endl; return 0;}
        }
    }
    cout << "NO" << endl;
	return 0;
}