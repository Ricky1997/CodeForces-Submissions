#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
bool cmp2(const pair<int,int> &p1, const int v)
{
    if(p1.first<v)
        return true;
    else
        return false;
}
int main()
{
	int n,c,d,i,x,m,y,ans=0;
	char z;
	vector< pair <int,int> > v1;
	vector< pair <int,int> > v2;
	vector< pair <int,int> > p1;
	vector< pair <int,int> > p2;
	cin >> n >> c >> d ;
	for(i=0;i<n;i++)
	{
		cin >> x >> y >> z; 
		if(z=='C')
		{
			if(y <=c ){ v1.push_back( make_pair(y,x) ); }
		}
		else
		{
			if(y <= d){ v2.push_back( make_pair(y,x) ); }
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	if(v1.size()>=1)
	{
		p1.push_back( make_pair(v1[0].second,0) );
	}
	if(v2.size()>=1)
	{
		p2.push_back( make_pair(v2[0].second,0) );
	}
	for(i=1;i<v1.size();i++)
	{
		if(v1[i].second >= p1[i-1].first)
		{
			p1.push_back( make_pair(v1[i].second,i) );
		}
		else
		{
			p1.push_back( make_pair(p1[i-1].first,p1[i-1].second) );
		}
	}
	for(i=1;i<v2.size();i++)
	{
		if(v2[i].second >= p2[i-1].first)
		{
			p2.push_back( make_pair(v2[i].second,i) );
		}
		else
		{
			p2.push_back( make_pair(p2[i-1].first,p2[i-1].second) );
		}
	}
	if(v1.size()>=1 && v2.size()>=1)
	{
		ans=p1[p1.size()-1].first + p2[p2.size()-1].first;
	}
	m=ans;
	int temp=0,ind=0;
	if(v1.size()>=2)
	{
		for(i=0;i<v1.size();i++)
		{
			temp=v1[i].second;
			ind=lower_bound(v1.begin(),v1.end(),c- v1[i].first,cmp2)-v1.begin();
			if(ind == v1.end()-v1.begin()){ind-=1;}
			else
			{
				if( v1[ind].first !=  c - v1[i].first ){ind-=1;} 
			}
			if(ind < 0){ continue; }
			if(i!=p1[ind].second)
			{
				temp+=p1[ind].first;
				m=max(temp,m);
			}	
		}
	}
	temp=0,ind=0;
	if(v2.size()>=2)
	{
		for(i=0;i<v2.size();i++)
		{
			temp=v2[i].second;
			ind=lower_bound(v2.begin(),v2.end(),d- v2[i].first,cmp2)-v2.begin();
			if(ind == v2.end()-v2.begin()){ind-=1;}
			else
			{
				if( v2[ind].first !=  d - v2[i].first ){ind-=1;} 
			}
			if(ind < 0){ continue; }
			if(i!=p2[ind].second)
			{
				temp+=p2[ind].first;
				m=max(temp,m);
			}	
		}
	}
	cout << m <<endl;
}