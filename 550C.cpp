#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	string x;
	cin >> x;
	int i=0,n=x.length();
	int d1,d2,d3;
	int j,k,l;
	int count=0;
	for(i=0;i<n;i++)
	{
	    int y=x[i]-'0';
	    if(y==0){cout << "YES" << endl << 0 << endl; return 0;}
	    if(y==8){cout << "YES" << endl << 8 << endl; return 0;}
	}
	if(n==1){ if(x[0]=='8'){cout << "YES" << endl << 8 << endl; return 0;} else {cout << "NO" << endl; return 0;}}
	for(i=16;i<100;i+=8)
	{
		d1=i/10;
		d2=i%10;
		for(j=0;j<n;j++)
		{
			int u=x[j]-'0';
			if(u==d1)
			{
				for(k=j+1;k<n;k++)
				{
					int v=x[k]-'0';			
					if(v==d2)
					{
						cout << "YES" << endl;
						cout << d1<< d2;
						return 0;	
					}		
				}
			   break;
			}
		}
	}
	for(i=104;i<1000;i+=8)
	{
		d1=i/100;
		d2=(i%100)/10;
		d3=(i%100)%10;
		for(j=0;j<n;j++)
		{
			int u=x[j]-'0';
			if(u==d1)
			{
				for(k=j+1;k<n;k++)
				{
					int v=x[k]-'0';			
					if(v==d2)
					{
						for(l=k+1;l<n;l++)
						{
							int w= x[l]-'0';
							if(w==d3)
							{
								cout << "YES" << endl;
								cout << d1<< d2<< d3;
								return 0;
							}
						}
					  break;
					}		
				}
			   break;
			}
		}
	}
	cout << "NO" <<endl;
	return 0;
}