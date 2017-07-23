#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
vector <long long int > a;
bool fn(vector<long long int> &A,long double d)
{
	int k=upper_bound(A.begin(),A.end(),A[0]+2*d)-A.begin();
	if(k==A.size()){return true;}
	else if(A[k]>=A[A.size()-1]-2*d){return true;}
	else
	{
		int j=lower_bound(A.begin(),A.end(),A[A.size()-1]-2*d)-A.begin()-1;
		if(j<=0){return true;}
		if(j<=k){return true;}
		if(A[k]+2*d >=A[j]){return true;}
		return false;
	}
}
int main()
{
	cin >> n;
	long long int x;
	for(int i=0;i<n;i++){cin >> x;a.push_back(x);}
	sort(a.begin(),a.end());
	a.erase( unique( a.begin(), a.end() ), a.end() );
	n=a.size();
	if(n==1){cout << 0 << endl ;cout << a[0] << " " << a[0] << " " << a[0] ;return 0;}
	if(n==2){cout << 0 << endl ;cout << a[0] << " " << a[1] << " " << a[1] ;return 0;}
	if(n==3){cout << 0 << endl ;cout << a[0] << " " << a[1] << " " << a[2] ;return 0;}
	long long int lo=0;long long int hi=a[n-1];
	long long int mi=INT_MAX;
	while(lo<=hi)
	{
		long long int mid= lo+(hi-lo)/2;
		if(fn(a,mid)){mi=min(mi,mid);hi=mid-1;}
		else{lo=mid+1;}
	}
	long long int d=mi;
	long double z = mi;
	long double z1=z-1+0.5;
	if(fn(a,z1)){z=z1;cout << setprecision(18)<<z1 << endl;}
	else{cout << setprecision(18)<<z << endl;}
	long double fi=a[0]+z;
	int j=0,cnt=1;
	cout << setprecision(18) << fi << " ";
    for(int i=0;i<n && cnt<3;)
    {
        while(a[i]<=a[j]+2*z){i++;}
        if(i>=n)
        {
            if(cnt==1){cout << setprecision(18) << fi << " " << fi;return 0;}
            if(cnt==2){cout << setprecision(18) << a[j]+z;return 0;}
        }
        else{cout << setprecision(18) << a[i]+z<< " ";j=i;cnt++;}
    }
	return 0;
}
