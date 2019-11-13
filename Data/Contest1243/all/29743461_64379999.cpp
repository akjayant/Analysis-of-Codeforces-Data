#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define se second
#define pb push_back
#define mp make_pair
#define boost cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
#define pii pair<ll, ll>

const int N = 1e5 + 1100, mod = 1e9 + 7, inf = 1e9 + 7;
int q, n;
int a[30], b[30];

int main(){
    boost;
    cin >> q;
    while(q--){
        cin >> n;
        string st, sp;
        cin >> st >> sp;
        bool ok = false;
        for(int i = 0; i < st.size(); i++){
            if(st[i] != sp[i]){
                for(int j = i + 1; j < sp.size(); j++){
                    if(sp[j] == sp[i] && st[j] == st[i]){
                        swap(st[i], sp[j]);
                        ok = true;
                        break;
                    }
                }
                break;
            }
        }
        if(st != sp){
            cout << "No\n";
        }else cout << "Yes\n";
    }
    return 0;
}
