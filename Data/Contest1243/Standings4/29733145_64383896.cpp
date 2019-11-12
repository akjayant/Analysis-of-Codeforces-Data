                                        ///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))

using namespace std;
string a;
string b;
void nhap()
{
    int n;
    cin>>n;
    cin>>a;
    cin>>b;
    a=' '+a;
    b=' '+b;
    int cnt=0;
    int c1=0;
    int c2=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i])
            {
                if(c1==0) c1=i;
                else c2=i;
                cnt++;
            }
        if(cnt>2)
        {
            cout<<"No"<<'\n';
            return ;
        }
    }
    if(cnt==2)
    {
        if(a[c1]==a[c2]&&b[c1]==b[c2]) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
    else
    {
        cout<<"No"<<'\n';
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen(Zo".inp","r",stdin);
//    freopen(Zo".out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    nhap();
}
