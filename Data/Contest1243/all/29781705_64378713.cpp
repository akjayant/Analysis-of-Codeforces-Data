#include <bits/stdc++.h>
#define PI 2*asin(1)
#define int long long
#define mod 1000000007
#define all(a) begin(a),end(a)
#define fore(i, j, n) for(long long i = j; i < n;i++)

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int qwe; cin >> qwe;
    while(qwe--) {
        int n; cin >> n;
        string s,t; cin >> s >> t;
        int c = 0;
        char a = 0,b = 0,a1 = 0,b1 = 0;
        bool flag = true;
        fore(i,0,n){
            if(s[i] != t[i]){
                c++;
                if(c==1){ a = s[i]; b = t[i];}
                if(c == 2){a1 = s[i]; b1 = t[i];}
                if(c > 2){flag = false; break;}
            }
        }
        if(flag){
            if(a == a1 && b1 == b) cout << "Yes\n";
            else cout << "No\n";
        }else{ cout << "No\n";}
    }
}