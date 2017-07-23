#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int a[100009];
long long int b[100009];
vector <int> ans;
long long int gcd(long long int a, long long int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int main()
{
	int n;
	cin >> n ;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		b[i]=a[i];
		if(a[i]%2==0){a[i]=0;}
		else{a[i]=1;}
	}
	long long int k = b[0];
	for(int i=0;i<n;i++){	k=gcd(k,b[i]);	}
	if(k!=1){cout << "YES" << endl; cout << 0 << endl; return 0;}	
	int cnt=0,i,yo=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==1){cnt+=1;if(i==n-1){ans.push_back(cnt);}}
		else if(a[i]==0)
		{
			ans.push_back(cnt);	cnt=0;
		}
	}
	for(i=0;i<ans.size();i++)
	{
		yo+=( (int)ceil(float(ans[i])/float(2)) + ans[i]%2); 
	}
	cout << "YES" << endl << yo << endl;
	return 0;
}