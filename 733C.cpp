int Solution::evalRPN(vector<string> &A) {
    int n=A.size();
    if(n==1){return A[0];}
    int i=2;
    int j=1;
    int prev=A[0];
    while(i<=n)
    {
    	if(A[i].length()==1)
    	{
    		int x=A[i][0];
    	}
        if(x==43)
        {
           prev= char((int)(prev-'0')+(int)(A[j]-'0') + '0');
           j--;
           
        }
        else if(x==45)
        {
           prev= char((int)(prev-'0')-(int)(A[j]-'0') + '0');
           j--;
        }
        else if (x==42)
        {
           prev= char((int)(prev-'0')*(int)(A[j]-'0') + '0');
           j--;
        }
        else if(x==47)
        {
           prev= char((int)(prev-'0')/(int)(A[j]-'0') + '0');
           j--;
        }
        else{next=A[i];}
        i++;
    }
    
    
}
