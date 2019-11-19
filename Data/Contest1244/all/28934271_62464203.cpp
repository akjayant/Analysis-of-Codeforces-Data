#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define endl '\n'
const int mod=1e9+7;
int p(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b%2)
            res*=a;
        a*=a;
        a%=mod;
        b/=2;
        res%=mod;
    }
    return res;
}
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
    	int a,b,c,d,k;
    	cin>>a>>b>>c>>d>>k;
    	int x=a/c+(a%c!=0);
    	int y=b/d+(b%d!=0);
    	if(x+y>k)	
    		cout<<-1<<endl;
    	else
    	cout<<x<<" "<<y<<endl;
    }
}
    