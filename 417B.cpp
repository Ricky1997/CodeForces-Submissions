#define p 1000000007
#define ll long long 
ll f[101];
 
ll pow(ll a, ll b, ll MOD)
{
 ll x=1,y=a; 
 while(b > 0)
 	{
 		if(b%2 == 1)
 	{
 		x=(x*y);
 		if(x>MOD) x%=MOD;
 	}
 	y = (y*y);
 	if(y>MOD) y%=MOD; 
 	b /= 2;
 	}
 return x;
}
ll InverseEuler(ll n, ll MOD)
{
 return pow(n,MOD-2,MOD);
}
 
ll C(ll n, ll r, ll MOD)
{
 
 return (f[n]*((InverseEuler(f[r], MOD)*InverseEuler(f[n-r], MOD))%MOD))%MOD;
}
long long int fn(long long int n)
{
    if(n==0 || n==1){return 1;}
    else
    {
        long long int k=1,g=0;
        while(k<=n)
        {
            k*=2;
            g++;
        }
        g--;
        if(g==0){return 1;}
        long long int x=pow(2,g-1,p);
        x=x%p;
        long long int m=n+1-(2*x);
        m=m%p;
        long long int l=x-1+min(m,x);
        l=l%p;
        long long int y=0;
        long long int r=x-1+max(y,m-x);
        r=r%p;
        long long int e=p;
        return ((C(n-1,l,e)%p)*(fn(l)%p)*(fn(r)%p))%p;
    }
}
int Solution::solve(int A) {
    f[0]=1;
    int i,j;
    long long int x=A;
	f[0] = 1;
	for(int i = 1 ; i <= 109 ; i++)
		f[i] = (f[i-1]*i)%p;
	int z =(int)((fn(x)+p)%p);
    return z;
}
