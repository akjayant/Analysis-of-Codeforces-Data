#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    for(long long int t=1;t<=n;t++)
    {
        long long int a,b,c,s=0;
        cin>>a>>b>>c;
        if(b>=c/2)
        {
            if(c%2==0)
        {s+=c+c/2;
        b-=c/2;
        }
        else
        {
            s+=c-1+c/2;
            b-=c/2;
        }
        if(b>=a*2)
        s+=a+a*2;
        else
        {
             if(b%2==0)
        {s+=b+b/2;
        b=0;
        }
        else
        {
            s+=b-1+b/2;
            b=0;
        }
        }
        }
        else
        {
            s+=b+2*b;
            
        }
        cout<<s<<endl;
    }
        return 0;
        
    
}