#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int a[123456]={-1};
int main()
{
	string x,y;
	cin >> x;
	int n,i,j=0,k=0,u=0;
	cin >> n;
	vector< pair<int,string> > v1;
	for(i=0;i<n;i++)
	{
		cin >> y;
		v1.push_back(make_pair(y.length(),y));
	}
	sort(v1.begin(),v1.end());
	vector<string>v;
	for(i=0;i<n;i++){v.push_back(v1[i].second);}
	v.erase(unique(v.begin(),v.end()),v.end());
	int m=x.length();
    for(i=0;i<123456;i++){a[i]=-1;}
	for(i=0;i<v.size();i++)
	{
		string p=v[i];
		int si=p.length();
		for(j=0;j<m-si+1;j++)
		{
			int ind=0;
			while(ind<si)
			{
				if(p[ind]== x[j+ind]){ind++;}
				else{break;}
			}
			if(ind==si)
			{
			    u=0;
				for(u=0;u<si-1;u++)
				{
					if(a[j+u]!=-1)
					{
						if(u+a[j+u]<si)
						{
							a[j]=u+a[j+u];
							break;
						}
					}
				}
				if(u==si-1){a[j]=si-1;}
			}
		}
	}
	if(a[m-1]==-1){a[m-1]=1;}
	for(i=m-2;i>=0;i--)
	{
		if(a[i]==-1)
		{
			a[i]=1+a[i+1];
		}
	}
	int ans=0,ind=0;
	for(i=0;i<m;i++)
	{
		if(a[i]>=ans){ans=a[i];ind=i;}
	}
	cout << ans << " " << ind <<endl; return 0;

}
