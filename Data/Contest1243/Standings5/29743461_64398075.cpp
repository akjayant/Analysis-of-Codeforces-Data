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
vector <pii> vec;


int main(){
    boost;
    cin >> q;
    while(q--){
        cin >> n;
        string st, sp;
        cin >> st >> sp;
        bool ok = false;
        vec.clear();
        for(int i = 0; i < st.size() - 1; i++){
            if(st[i] != sp[i]){
                int x = -1;
                if(x == -1){
                    for(int j = i + 1; j < sp.size(); j++){
                        if(sp[j] == st[i]){
                            swap(sp[j], st[i + 1]);
                            swap(st[i + 1], sp[i]);
                            vec.pb(mp(i + 1, j));
                            vec.pb(mp(i + 1, i));
                            x = 1;
                            break;
                        }
                    }
                }
                if(x == -1){
                    for(int j = i + 1; j < st.size(); j++){
                        if(st[j] == sp[i]){
                            swap(st[j], sp[i + 1]);
                            swap(st[i], sp[i + 1]);
                            vec.pb(mp(j, i + 1));
                            vec.pb(mp(i, i + 1));
                            x = 1;
                            break;
                        }
                    }
                }
                if(x == -1){
                    for(int j = i + 1; j < sp.size(); j++){
                        if(sp[j] == sp[i]){
                            swap(st[i], sp[j]);
                            vec.pb(mp(i, j));
                            break;
                        }
                    }
                }
                if(x == -1){
                    for(int j = i + 1; j < st.size(); j++){
                        if(st[j] == st[i]){
                            swap(st[j], sp[i]);
                            vec.pb(mp(j, i));
                            break;
                        }
                    }
                }
            }
        }
        if(st == sp){
            cout << "Yes\n" << vec.size() << "\n";
            for(int i = 0; i < vec.size(); i++){
                cout << vec[i].f + 1 << ' ' << vec[i].se + 1 << '\n';
            }
        }else cout << "No\n";
    }
    return 0;
}
