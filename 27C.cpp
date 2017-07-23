#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n,a[500000];

int main()
{
int i,j;
  cin >> n;
  for (i = 0;i<n;i++) {cin >> a[i];}
  for (i = 1;i<(n-1);i++)
     {
        if ((a[0] > a[i] && a[i] < a[i+1]) || (a[0] < a[i] && a[i] > a[i+1]))
         {
          cout<<3<<endl;
          cout<<1<<" "<<i+1<<" "<<i+2<<endl;        
          return 0;
          }
     }     
  cout<<0<<endl;
  return 0;
}
