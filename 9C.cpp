#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
vector<long long int> v;
int main()
{
	long long int n;
	cin >> n;
	v.push_back(0);
    v.push_back(1);
    v.push_back(10);
    long long int i=0,j=0,k=1;
    for(i=2;i<=515;)
    {
        long long int z=pow(10,k);
        for(j=1;j<i;j++)
        {
            v.push_back(z+v[j]);
        }
        v.push_back(10*z);
        k++;
        i*=2;
    }
    int x= lower_bound(v.begin(),v.end(),n)-v.begin();
    if(v[x]==n){cout << x; return 0;}
    else
    {
        cout << x-1 << endl;
        return 0;
    }
	return 0;
}