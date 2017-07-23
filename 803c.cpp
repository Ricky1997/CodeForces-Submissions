#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int n,k,t,i;
vector <long long int> s;
vector <long long int> f; 
int fn( long long int num){
   int count =-1;
   while (num !=0) {   
      count++;  
      num/=10;
   } 
   return count;
}
int main()
{
	cin >> n >> k;
	if(fn(k)*2 > fn(2*n) ){t=0;}
	else {t = (int)( (2*n)/(k*(k+1)) );}
	if(t==0){cout << -1 << endl; return 0;}
	long long int sum=0;
	for(i=1;i<=(long long int)sqrt(n);i++)
	{
		if(n%i==0)
		{
			s.push_back(i);
			if(n/i!=i){ f.push_back(n/i); }
		}
	}
	reverse(f.begin(),f.end());
	for(int j=0;j<f.size();j++){ s.push_back(f[j]); }
	for(i=s.size()-1;i>=0;i--)
	{
		if(s[i] <=( (2*n)/(k*(k+1)) ) )
		{
			for(int j=1;j<k;j++)
			{
				cout << (long long int)(s[i]*j) << " ";
				sum+=(long long int)(s[i]*j);
			}
			cout << n-sum << endl;
			return 0;
		}
	}


}