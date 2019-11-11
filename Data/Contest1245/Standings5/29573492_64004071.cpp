#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
  #define watch(x) cout << (#x) << " is " << (x) << '\n'
  #define dashline() cout << "=============\n"
#else
  #define watch(x)
  #define dashline()
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MX = 1e9;
const ll MX2 = 3e18;
const double pi = acos(-1);

const int MOD = 1e9+7;
const int sz = 131072;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    string str;
    cin>>str;
    str+='.';
    int n,cnt,i;
    vi vs;
    char lx=0;
    ll d[100011]={1,1};

    for(i=2;i<=100000;i++) {d[i]=d[i-2]+d[i-1]; d[i]%=MOD;}

    for(char x:str)
    {
        if (x=='m' || x=='w')
        {
            cout<<0;
            return 0;
        }
        if (lx==x) cnt++;
        if (lx=='u' && x!='u')
            vs.push_back(cnt);
        if (lx=='n' && x!='n') vs.push_back(cnt);
        if (lx!=x) cnt=1;
        lx=x;
    }

    ll ans=1;

    for(int x:vs)
    {
        ans*=d[x];
        watch(x);
        watch(d[x]);
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}
