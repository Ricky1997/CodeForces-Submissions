#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int m,t;
	cin >> m >> t;
	int rem1=t-1,rem2=t;
	int s[m]={0};
	s[0]=1;
	int l[m]={0};
	if(m==1 && t==0){ cout << 0 << " " << 0 << endl; return 0;}
	if( t >=1 && t<= 9*m)
	{
		for(int i=m-1;i>=0;i--)
		{
			if(rem1-9 >=0){ s[i]+=9; rem1=rem1-9;}
			else{s[i]+=rem1; break;}
		}
		for(int i=0;i<m;i++)
		{
			if(rem2-9 >=0){ l[i]+=9; rem2=rem2-9;}
			else{l[i]+=rem2; break;}
		}
		for(int i=0;i<m;i++)
		{
			cout << s[i] ;
		}
		cout << " ";
		for(int i=0;i<m;i++)
		{
			cout << l[i] ;
		}
	}
	else
	{
		cout << -1 << " " << -1 << endl;
	}
	return 0;
}