#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<stack>
#include<algorithm>
#include<string>
#include<string.h>
#include<assert.h>
#include<iomanip>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll fpb(ll a, ll b){
    if(b == 0)return a;
    return fpb(b, a % b);
}

char ans[105];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a, b, c; cin >> a >> b >> c;
        string s; cin >> s;
        for(int i = 0; i < s.length(); ++i){
            ans[i] = ' ';
            if(s[i] == 'P'){
                if(c > 0)ans[i] = 'S', c--;
            }else if(s[i] == 'S'){
                if(a > 0)ans[i] = 'R', a--;
            }else{
                if(b > 0)ans[i] = 'P', b--;
            }
        }

        int win = 0;
        for(int i = 0; i < s.length(); ++i){
            if(ans[i] != ' '){
                win++;
                continue;
            }
            if(a)ans[i] = 'R', a--;
            else if(b)ans[i] = 'P', b--;
            else if(c)ans[i] = 'S', c--;
        }

        if(win >= (n + 1) / 2){
            cout << "YES" << endl;
            for(int i = 0; i < s.length(); ++i){
                cout << ans[i];
            }cout << endl;
        }else cout << "NO" << endl;
    }
}