
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int spf[10000009]={0},af[10000009]={0},bf[10000009]={0};
int n,m;
int a[100001],b[100001];
# define MAXN 10000001
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++){spf[i] = i;}
    for (int i=4; i<MAXN; i+=2){spf[i] = 2;}
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i){
                if (spf[j]==j){spf[j] = i;}
            }
        }
    }
}
void fn(int N,int *a)
{
	int curr = spf[N];
    int cnt = 1;
    while (N > 1)
    {
        N /= spf[N];
        if (curr == spf[N])
        {
            cnt++;
            continue;
        }
        a[curr]+=cnt;
        curr = spf[N];
        cnt = 1;
    }
}
int check(long long int a)
{
	long long int k=a;
	int cnt=0;
	while(a<MAXN){a*=k;cnt++;}
	return cnt;
}
int main()
{
	cin >> n >> m;
	sieve();
	int i,j;
	vector<int>f1;
	vector<int>f2;
	for(i=0;i<n;i++){cin >> a[i];fn(a[i],af);}
	for(i=0;i<m;i++){cin >> b[i];fn(b[i],bf);}
	for(i=0;i<10000001;i++)
	{
		if(af[i]!=0 && bf[i]!=0)
		{
			if(af[i]>=bf[i]){af[i]-=bf[i];bf[i]=0;}
			else{bf[i]-=af[i];af[i]=0;}
		}
		if(af[i]!=0)
		{
			int x=check((long long int)i);
			if(x>=af[i]){f1.push_back( pow(i,af[i]) );}
			else
			{
				while(af[i]>0)
				{
					f1.push_back(pow(i,min(x,af[i])));
					af[i]-=x;
				}
			}
		}
		if(bf[i]!=0)
		{
			int x=check((long long int)i);
			if(x>=bf[i]){f2.push_back(pow(i,bf[i]));}
			else
			{
				while(bf[i]>0)
				{
					f2.push_back(pow(i,min(x,bf[i])));
					bf[i]-=x;
				}
			}
		}
	}
	if(f1.size()==0){f1.push_back(1);}
	if(f2.size()==0){f2.push_back(1);}
	cout << f1.size() << " " << f2.size() << endl;
	for(i=0;i<f1.size();i++)
	{
	    long long int z=f1[i];
	    z*=f1[i+1];
	    if(f1[i+1]>=MAXN){cout << f1[i] << " ";}
	    else{cout << z << " " ;i++;}
	}
	cout << endl;
	for(i=0;i<f2.size();i++)
	{
	    long long int z=f2[i];
	    z*=f2[i+1];
	    if(f2[i+1]>=MAXN){cout << f1[i] << " ";}
	    else{cout << z << " " ;i++;}
	}
	return 0;
}
