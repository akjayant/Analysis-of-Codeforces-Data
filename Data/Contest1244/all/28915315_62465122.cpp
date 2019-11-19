#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int e=a/c;
        int f=b/d;
        if(a%c) e++;
        if(b%d) f++;
        if(k<e+f)
        {
            cout<<"-1"<<'\n';
            continue;
        }
        else cout<<e<<' '<<k-e<<'\n';
    }
}

