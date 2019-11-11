#include <bits/stdc++.h>
#define x first
#define y second
//#define int long long

using namespace std;
int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int qq = 1;
    cin >> qq;
    for(int qqq = 0; qqq<qq; qqq++){
        int a, b, c, n;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        int ac = 0, bc = 0, cc = 0;
        for(auto z:s){
            if(z=='R'){
                bc++;
            } else if(z=='P'){
                cc++;
            } else if(z=='S'){
                ac++;
            }
        }
        char ans[n];
        if(min(a, ac)+min(b, bc)+min(c, cc)>=n/2+n%2){
            cout << "YES\n";
            for(int i = 0; i<n; i++)
                ans[i] = ' ';
            for(int i = 0; i<n; i++){
                if(s[i]=='R'){
                    if(b>0){
                        ans[i] = 'P';
                        b--;
                    }
                } else if(s[i]=='P'){
                    if(c>0){
                        ans[i] = 'S';
                        c--;
                    }
                } else if(s[i]=='S'){
                    if(a>0){
                        ans[i] = 'R';
                        a--;
                    }
                }
            }
            for(int i = 0; i<n; i++){
                if(ans[i]!=' '){
                    cout << ans[i];
                } else if(a>0){
                    cout << "R";
                    a--;
                } else if(b>0){
                    cout << "P";
                    b--;
                } else cout << "S";
            }
            cout << "\n";
        } else cout << "NO\n";
    }
    return 0;
}
