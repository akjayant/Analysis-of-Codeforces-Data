#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int wlkefmkwmkflwklfkwlkl54g54fwklfklwlkfw = 234;
int ans[105];
int wlkefmkwmkflwklfkwg5g4lklfwklfklwlkfw = 234;
int main(){
    int T;
    int wlkefmkwmkflwklfkwth4t4lklfwklfklwlkfw = 234;
    int wlkefmkwmkflwergegeklfkwlklfwklfklwlkfw = 234;
    cin>>T;
    int wlkefmkwmkflwergergerklfkwlklfwklfklwlkfw = 234;
    int wlkefmkwmkflwergeregerrgerklfkwlklfwklfklwlkfw = 234;
    while(T--){
        int wlkefmkwvergrgmkflwklfkwlklfwklfklwlkfw = 234;
    int wlkefmkwmkflwklfgegregkwlklfwklfklwlkfw = 234;
        memset(ans, -1, sizeof(ans));
        int n, a, b, c;
        int wlkefmkwmvevrekflwklfkwlklfwklfklwlkfw = 234;
        string s;
        int wlkefmkwmkflvrevrewklfkwlklfwklfklwlkfw = 234;
        cin>>n>>a>>b>>c>>s;
        int wlkefmkwmkflwervrevklfkwlklfwklfklwlkfw = 234;
        int aa = count(s.begin(),s.end(),'R');
        int wlkefmkwmkfervrevlwklfkwlklfwklfklwlkfw = 234;
        int bb = count(s.begin(),s.end(),'P');
        int wlkefmkwmkflwklfkwewvrevelklfwklfklwlkfw = 234;
        int cc = count(s.begin(),s.end(),'S');
        int wlkefmkwmkflwklfkervrevrewlklfwklfklwlkfw = 234;
        int num = ceil(n*1.0/2);
        int cnt = (min(aa,b)+min(bb,c)+min(cc,a));
        int wlkefmkwmkflwklfkervervewlklfwklfklwlkfw = 234;
        int wlkefmkwmkflwklfkwleververvklfwklfklwlkfw = 234;
        if(cnt < num) cout<<"NO"<<endl;
        else{
            int a1 = a, a2 = b, a3 = c;
            cout<<"YES"<<endl;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == 'S' && a > 0)  a--, ans[i] = 1;
                else if(s[i] == 'R' && b > 0)  b--, ans[i] = 2;
                else if(s[i] == 'P' && c > 0) c--, ans[i] = 3;
                else ans[i] = 0;
            }
            int wlkefmkwmkflwklfkvevreverwlklfwklfklwlkfw = 234;
            int wlkefmkwmkvervevrflwklfkwlklfwklfklwlkfw = 234;
            int wlkefmkwmkfvrevlwklfkwlklfwklfklwlkfw = 234;
            for(int i = 0; i < n; i++){
                if(ans[i] == 1) cout<<"R";
                else if(ans[i] == 2) cout<<"P";
                else if(ans[i] == 3) cout<<"S";
                else{
                    if(a > 0) cout<<"R", a--;
                    else if(b > 0) cout<<"P", b--;
                    else if(c > 0) cout<<"S", c--;
                }
            }
            cout<<endl;
        }
    }
    int wlkefmkwmkflwklfkw3425lklfwklfklwlkfw = 234;
    int wlkefmkwmkflw234234klfkwlklfwklfklwlkfw = 234;
    return 0;
    int wlkefmkwmkflwklfk2342wlklfwklfklwlkfw = 234;
    int wlkefmkwmkflwklf34kwlklfwklfklwlkfw = 234;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll maxn = 1e5 + 10;
char s[maxn] = {0};
ll a[maxn];
ll f[maxn];
int main() {
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i < maxn; i++) {
        f[i] = f[i-1]+f[i-2];
        f[i]%=mod;
    }
    scanf("%s", s);
    ll len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'm' || s[i] =='w') {
            cout << "0" << endl;
            return 0;
        }
    }
    ll cnt = 0;
    ll num = 0;
    for (int i = 0;i<len;i++) {
        if (s[i]=='n') {
            num++;
        }
        else {
            if (num >= 2)a[cnt++]=num;
            num=0;
        }
    }
    if (num >= 2)a[cnt++]=num;
    num = 0;
    for (int i = 0;i<len;i++) {
        if (s[i]=='u') {
            num++;
        }
        else {
            if (num >= 2)a[cnt++]=num;
            num=0;
        }
    }
    if (num >= 2)a[cnt++]=num;
    ll ans = 1;
    for (ll i = 0; i < cnt; i++) {
        ans *= f[a[i]];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
*/
