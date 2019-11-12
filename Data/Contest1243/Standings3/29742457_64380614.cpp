#include <bits/stdc++.h>
using namespace std;
#define re return
#define ll long long
#define du double
#define co continue
#define gcd __gcd
#define br break
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    fast();
    ll k,n,v,sum;
    string s,t;
    cin >> k;
    ll a[1000+10];
    while(k--){
        sum=0;
        cin >> n;
        cin >> s;
        cin >> t;
        for (int i=0;i<n;++i) if (s[i]!=t[i]) sum++;
        if (sum==0){
            cout << "YES" << "\n";
            co;
        }
        if (sum!=2){
            cout << "NO" << "\n";
            co;
        }
        char x1,x2,y1,y2;
        sum=0;
        for (int i=0;i<n;++i) if (s[i]!=t[i] && !sum){ x1=s[i]; x2=t[i]; sum++;} else if (s[i]!=t[i]){y1=s[i]; y2=t[i];}
        if (x1==y1 && x2==y2){
            cout << "YES" << "\n";
            co;
        }
        cout << "NO" << "\n";
    }
    re 0;
}
