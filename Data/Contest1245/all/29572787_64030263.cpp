#include<bits/stdc++.h>
typedef long long int ll;

using namespace std;

const int MAXN = 2e5 + 123;
const ll MOD = 1e9 + 7;
int l[MAXN], r[MAXN], ch[MAXN];

int main(){
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        int a, b, c, a1 = 0, b1 = 0, c1 = 0;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        for(int i = 0; i < n; i ++){
            if(s[i] == 'S')
                a1 ++;
            if(s[i] == 'R')
                b1 ++;
            if(s[i] == 'P')
                c1 ++;
        }
        int alice = min(a, a1) + min(b, b1) + min(c, c1);
        char ans[200];
        if(alice >= (n / 2 + (n % 2))){
            cout << "YES\n";
            for(int i = 0; i < n; i ++){
                if(s[i] == 'S' && a)
                    ans[i] = 'R', a --;
                else if(s[i] == 'R' && b)
                    ans[i] = 'P', b --;
                else if(s[i] == 'P' && c)
                    ans[i] = 'S', c --;
                else
                    ans[i] = 'F';
            }
            for(int i = 0; i < n; i ++){
                if(ans[i] != 'F')
                    cout << ans[i];
                else{
                    if(a){
                        cout << 'R';
                        a --;
                    }
                    else if(b){
                        cout << 'P';
                        b --;
                    }
                    else{
                        cout << 'S';
                        c --;
                    }
                }
            }
            cout << "\n";
        }
        else
            cout << "NO\n";
        t --;
    }
}
