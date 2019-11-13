//    KHAz
#include <bits/stdc++.h>
#define maxn 200005
#define Task ""
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define pii pair< int , int >
#define reset(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
int T;
int n, x[4];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> T;
    while (T--)
    {
        
        cin >> n >> x[1] >> x[2] >> x[3];
        string s;
        string res="";
        cin >> s;
        for(int i=0;i<n;i++) res+=" ";
        for(int i=0;i<n;i++)
        {
            if (s[i]=='R'&&x[2])
            {  res[i]='P';
             x[2]--;
            }
            if (s[i]=='P'&&x[3])
            {  res[i]='S'; x[3]--;}
            if (s[i]=='S'&&x[1])
            {res[i]='R';
            x[1]--;
            }
        }
        if (x[1]+x[2]+x[3]>n/2)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i=0;i<n;i++) if (res[i]==' ')
        {
            if (x[1]) res[i]='R', x[1]--;
            else
                if (x[2]) res[i]='P', x[2]--;
            else
                if (x[3]) res[i]='S', x[3]--;
        }
        cout << res;
        cout <<'\n';
    }
    return 0;
}
