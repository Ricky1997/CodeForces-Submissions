#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int i,y;
	vector< pair<string,int> >v;
	string x;
	for(i=0;i<n;i++)
	{
		cin >> x;
		if(x[0]=='i' || x[0]=='g') {cin >> y; v.push_back(make_pair(x,y));}
		else { v.push_back(make_pair(x,0));}
	}
	priority_queue<int,vector<int>,greater<int> >q;
	vector< pair<string,int> >f;
	string in="insert";
	string re="removeMin";
	for(i=0;i<n;i++)
	{
		if(v[i].first[0]=='g')
		{
			if(q.empty())
			{
				f.push_back(make_pair(in,v[i].second));
				f.push_back(make_pair(v[i].first,v[i].second));
				q.push(v[i].second);
			}
			else if(q.top()==v[i].second){f.push_back(make_pair(v[i].first,v[i].second));continue;}
			else
			{
				if(q.top()>v[i].second)
				{
					f.push_back(make_pair(in,v[i].second));
					f.push_back(make_pair(v[i].first,v[i].second));
					q.push(v[i].second);
				}
				else
				{
					while(!q.empty() && q.top()<v[i].second)
					{
						f.push_back(make_pair(re,0));
						q.pop();
					}
					if(q.empty())
					{
						f.push_back(make_pair(in,v[i].second));
						f.push_back(make_pair(v[i].first,v[i].second));
						q.push(v[i].second);
					}
					else
					{
						if(q.top()==v[i].second){f.push_back(make_pair(v[i].first,v[i].second));continue;}
						else
						{
							f.push_back(make_pair(in,v[i].second));
							f.push_back(make_pair(v[i].first,v[i].second));
							q.push(v[i].second);
						}
					}
				}
			}
		}
		else if(v[i].first[0]=='r')
		{
			if(q.empty())
			{
				f.push_back(make_pair(in,0));
				f.push_back(make_pair(re,0));
			}
			else
			{
				f.push_back(make_pair(re,0));
				q.pop();
			}
		}
		else
		{
			f.push_back(make_pair(v[i].first,v[i].second));
			q.push(v[i].second);
		}
	}
	cout << f.size() << endl;
	for(i=0;i<f.size();i++)
	{
		if(f[i].first[0]=='i' || f[i].first[0]=='g'){cout << f[i].first << ' ' << f[i].second << endl;}
		else
		{
			cout << f[i].first << endl;
		}
	}
	return 0;
}
