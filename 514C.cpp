#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
map<string,int> mp;
vector<string> v[600009];
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	string s;
	while(n--){
		cin>>s;
		v[s.size()].push_back(s);
	}
	while(m--){
        cin>>s;
		if(mp[s]==1){ cout<<"YES"<<endl; }
		else if(mp[s]==2){ cout<<"NO"<<endl; }
		else{
			int cnt=0;
			int l=s.size();
			int z=v[l].size();
			for(i=0;i<z;i++){
				cnt=0;
				for(j=0;j<l;j++){
					if(v[l][i][j]!=s[j]) cnt++;
					if(cnt>1) break;
				}
				if(cnt==1){
					cout<<"YES"<<"\n";
					mp[s]=1;
					break;
				}
			}
			if(cnt!=1){
				cout<<"NO"<<"\n";
				mp[s]=2;
			}
		}
	}
	return 0;
}
