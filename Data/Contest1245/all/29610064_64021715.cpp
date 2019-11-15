#include<cstring>
#include<iostream>
#define MAXN 100005
using namespace std;
typedef long long lld;
const lld mod = 1000000007;
lld f[MAXN];
char s[MAXN];
int main(){
    cin >> s;
    int len = strlen(s);
    for(int i = 0;i < len;++i){
        if(s[i] == 'm' || s[i] == 'w'){
            cout << 0 << endl;
            return 0;
        }
    }
    f[0] = 1;
    for(int i = 1;i <= len;++i){
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    int nxt = -1;
    lld ans = 1;
    for(int i = 0;i < len;i = nxt){
        nxt = i + 1;
        if(s[i] == 'n' || s[i] == 'u'){
            while(nxt < len && s[nxt] == s[i]) ++nxt;
            int le = nxt - i;
            ans = ans * f[le] % mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}