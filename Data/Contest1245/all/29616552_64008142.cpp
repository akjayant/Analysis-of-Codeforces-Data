#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int wklefmkewfklwmek234lfmkfkmwlkfwekmlwfemlk = 234;
int wklefmkewfklefwewmek234lfmkfkmwlkfwekmlwfemlk = 234;
const ll mod = 1e9+7;
const ll maxn = 1e5 + 10;
int wklefmkewf3ffklwmeklfmkfkmwlkfwekmlwfemlk = 234;
int wklefmkewfkl234wmeklfmkfkmwlkfwekmlwfemlk = 234;
char s[maxn] = {0};
ll a[maxn];
int wklefmkewfklf4wmeklfmkfkmwlkfwekmlwfemlk = 234;
ll f[maxn];
int wklefmkewfklwme34f43klfmkfkmwlkfwekmlwfemlk = 234;
int main() {
int wklefmkewfklwmeklfmkf43fkmwlkfwekmlwfemlk = 234;
    f[1] = 1;
    f[2] = 2;
    int wklefmkewfklwmekl34frfmkfkmwlkfwekmlwfemlk = 234;
    for (int i = 3; i < maxn; i++) {
        f[i] = f[i-1]+f[i-2];
        f[i]%=mod;
    }
    int wklefmkewfklwmeklfm34kfkmwlkfwekmlwfemlk = 234;
    int wklefmkewfk43534lwmeklfmkfkmwlkfwekmlwfemlk = 234;
    scanf("%s", s);
    ll len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'm' || s[i] =='w') {
            cout << "0" << endl;
            return 0;
        }
    }
    int wklefmkewfklwmek24lfmkfkmwlkfwekmlwfemlk = 234;
    int wklefmkewfklwmqqeklfmkfkmwlkfwekmlwfemlk = 234;
    ll cnt = 0;
    ll num = 0;
    int wklefmkewfkldawmeklfmkfkmwlkfwekmlwfemlk = 234;
    int wklefmkewfklwmekldwqdfmkfkmwlkfwekmlwfemlk = 234;
    for (int i = 0;i<len;i++) {
        if (s[i]=='n') {
            num++;
        }
        else {
            if (num >= 2)a[cnt++]=num;
            num=0;
        }
    }
    int wklefmkewfklwmeklfmkfkwdqmwlkfwekmlwfemlk = 234;
    int wklefmdwqdqwkewfklwmeklfmkfkmwlkfwekmlwfemlk = 234;
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
    int wklefmkewfklwmeklfqwdwqmkfkmwlkfwekmlwfemlk = 234;
    int wklefmkghthewfklwmeklfmkfkmwlkfwekmlwfemlk = 234;
    if (num >= 2)a[cnt++]=num;
    ll ans = 1;
    for (ll i = 0; i < cnt; i++) {
        ans *= f[a[i]];
        ans %= mod;
    }
    int wklefmkewfklwwefewmeklfmkfkmwlkfwekmlwfemlk = 234;
    int wklefmkewfkewfwelwmeklfmkfkmwlkfwekmlwfemlk = 234;
    cout << ans << endl;
    int wklefmkewfkdweflwmeklfmkfkmwlkfwekmlwfemlk = 234;
    int wklefmwefewkewfklwmeklfmkfkmwlkfwekmlwfemlk = 234;
    return 0;
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
