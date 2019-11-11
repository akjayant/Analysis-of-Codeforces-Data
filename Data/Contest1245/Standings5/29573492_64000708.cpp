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

const int MOD = 2e9;
const int sz = 131072;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int T; cin>>T;
    int a,b,c;
    string str;
    while(T--)
    {
        int n; cin>>n;
        cin>>a>>b>>c;
        cin>>str;
        int ans[111]={};
        int cnt=0,i;    
        for(i=0;i<n;i++)
        {
            char x=str[i];
            if (x=='R' && b) {b--; ans[i]=1;cnt++;}
            else if (x=='P' && c) {c--; ans[i]=2;cnt++;}
            else if (x=='S' && a) {a--; ans[i]=3;cnt++;}
        }
        //1P 2S 3R
        if ((n+1)/2 >cnt)
        {
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";
        for(i=0;i<n;i++)
        {
            if (ans[i])
            {
                if (ans[i]==1) cout<<'P';
                if (ans[i]==2) cout<<'S';
                if (ans[i]==3) cout<<'R';
            }
            else
            {
                if (a) {cout<<'R'; a--;}
                else if (b) {cout<<'P'; b--;}
                else {cout<<'S'; c--;}
            }
        }
        cout<<'\n';

    }

    return 0;
}
