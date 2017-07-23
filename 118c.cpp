#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,k,i,j,cnt=0,ans=0;
	pair <int,int> yo;
	yo = make_pair(100000,-1);
	cin >> n>> k;
	string x,temp;
	cin >> x;
	vector <int> v[10];
	int a[10]={0};
	
	for(i=0;i<x.length();i++){ v[x[i]-'0'].push_back(i); }
	for(i=0;i<10;i++)
	{
		a[0]=v[i].size();
		for(j=1;j<10;j++)
		{
			a[j]=0;
			if(i+j < 10){ a[j]+=v[i+j].size();  }
			if(i-j >= 0){ a[j]+=v[i-j].size(); } 
		}
		j=0;
		while(cnt<k && j<10)
		{
			if(a[j]<= k -cnt)
			{
				cnt+=a[j]; 
				ans+=a[j]*j;
			}
			else
			{
			    ans+=(k-cnt)*j;
				cnt+=( k - cnt) ;
			}
			j++;
		}
        if(ans < yo.first){ yo.first=ans; yo.second=i;}
		cnt=0;
		ans=0;
		for(int p =0;p<10;p++){a[p]=0;}
	}
	cout << yo.first  <<endl << yo .second << endl;




}