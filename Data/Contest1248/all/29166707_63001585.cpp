
/*
Nahid Hossain
Jahangirnagar University
Roll:54
*/
#include<bits/stdc++.h>
#define ll          long long int
#define db          double
#define ma 200050
#define mod 1000000007
using namespace std;
ll a[ma],b[ma];
int main()
{
    ll tc,n,i,j,m;
    cin>>tc;

    while(tc--)
    {
        cin>>n;
        ll ev=0,od=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]%2==1)od++;
            else ev++;
        }
        cin>>m;
        ll ev1=0,od1=0;
        for(i=1;i<=m;i++)
        {
            cin>>b[i];
            if(b[i]%2==1)od1++;
            else ev1++;
        }
        //cout<<"YES"<<endl;
        cout<<od*od1+ev*ev1<<endl;
    }
    return 0;
}
