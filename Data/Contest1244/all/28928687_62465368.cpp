#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    long long t,n,m,a,b,c,d,s=0,u,k,x=0;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        if((a-1)/c+1+(b-1)/d+1>k)cout<<-1<<endl;
        else cout<<(a-1)/c+1<<" "<<(b-1)/d+1<<endl;
    }

}
