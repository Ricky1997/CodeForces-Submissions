#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int a[4][4];
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			cin >> a[i][j];
		}
	}
	if(a[0][3]==1 && (a[0][0]==1 || a[0][1]==1 || a[0][2]==1 || a[1][0]==1 || a[2][1]==1 || a[3][2]==1))
	{
		cout << "YES" << endl; return 0;
	}
	if(a[1][3]==1 && (a[1][0]==1 || a[1][1]==1 || a[1][2]==1 || a[2][0]==1 || a[3][1]==1 || a[0][2]==1))
	{
		cout << "YES" << endl; return 0;
	}
	if(a[2][3]==1 && (a[2][0]==1 || a[2][1]==1 || a[2][2]==1 || a[3][0]==1 || a[0][1]==1 || a[1][2]==1))
	{
		cout << "YES" << endl; return 0;
	}
	if(a[3][3]==1 && (a[3][0]==1 || a[3][1]==1 || a[3][2]==1 || a[0][0]==1 || a[1][1]==1 || a[2][2]==1))
	{
		cout << "YES" << endl; return 0;
	}
	cout << "NO" << endl;
	return 0;
}