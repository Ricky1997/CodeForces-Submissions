#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
bool comp(int i,int j){return i>j;}
int n;
int main()
{
	cin >> n;
	char x[2*n][7];
	int t=2*n;
	int ans=0,y,i=0;
	int cnt=1;
	vector<int>v;
	map<int,int> m;
	std:: map <int,int>::iterator it;
    while(t>0)
	{
		scanf("%s",&x[i]);
		if(x[i][0]=='a')
		{
			scanf("%d",&y);
			v.push_back(y);
			m[y]=1;
		}
		else
		{
			if(v[v.size()-1]==cnt)
            {
                v.pop_back();
                it=m.find(cnt);
                m.erase (it);
                cnt++;
            }
			else
			{
				ans++;
                it=m.find(cnt);
                m.erase (it);
                v.clear();
                for(it=m.begin(); it!=m.end(); ++it)
                {
                 v.push_back(it->first);
                }
                reverse(v.begin(),v.end());
				cnt++;
			}
		}
		t--;
		i++;
	}
	cout << ans << endl;
 return 0;
}
