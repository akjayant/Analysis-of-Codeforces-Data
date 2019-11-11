#include <bits/stdc++.h>

using namespace std;
const int maxn = 100006;
typedef long long ll;
const ll mod = 1e9+7;

ll f[maxn];
char s[maxn];

int main() {

    cin>>s+2;
    int n = strlen(s+2);

    f[1]=1;
    for (int i=2;i<=n+1;i++) {
        if (s[i]=='m'||s[i]=='w') {
            cout<<"0"<<endl;
            return 0;
        }
        if ((s[i]=='u'&&s[i-1]=='u') ||
                (s[i]=='n'&&s[i-1]=='n'))
            f[i] = (f[i-1]+f[i-2])%mod;
        else f[i]=f[i-1];
    }
    cout<<f[n+1]<<endl;

    return 0;
}
