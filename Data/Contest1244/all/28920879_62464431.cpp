#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mp make_pair

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        ll x=(a+c-1)/c,y=(b+d-1)/d;
        if(x+y>k)
        {
            cout<<-1<<endl;
        }
        else
            cout<<x<<' '<<y<<endl;
    }

    return 0;
    }
//
