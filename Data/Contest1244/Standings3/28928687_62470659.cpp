#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    long long t,n,m,a,b,c,d,s=0,u,k,x=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>S;
        long long mi=10000;
        for(long long i=0; i<n; i++)
        {
            long long d=S[i]-'0';
            if(d==1)mi=min(mi,min(i+1,n-i));
        }
        if(mi==10000)cout<<n<<endl;
        else cout<<2*(n-mi+1)<<endl;
    }

}
