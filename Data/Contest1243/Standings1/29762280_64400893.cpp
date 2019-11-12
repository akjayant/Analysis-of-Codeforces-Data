#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) x.begin(),x.end()
#define len(x) (int)(x).size()
#define int long long

/*
#pragma GCC omptimize("unroll-loops")
#pragma optimize("SEX_ON_THE_BEACH")
#pragma GCC optimize("no-stack-protector")
#pragma comment(linker, "/STACK:10000000000")
*/


using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pari;
typedef vector<vi > matrix;

ld PI = 3.14159265358979323846;


typedef tree<int, null_type, less<int >,
    rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void volodya22(){
    #ifdef THERE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen("fibonacci.in", "r", stdin);
        //freopen("fibonacci.out", "w", stdout);
        //#define endl "\n"
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif

    cout.precision(7);
    cout << fixed;

}

struct Zdarovo{
    int b,ind,x,r,flag;
};

const int N = 1e6+7;
const ll MOD = 998244853;

const int INF = 1e18+7;


const int K = 300;


int n;
int arr[N];

int cnt[N];

void input(){
    int k;
    cin >> k;
    while(k--){

        for(int i = 0;i < K;i++)
            cnt[i] = 0;

        int n;
        string a,b;
        cin >> n;
        cin >> a >> b;
        for(int i = 0;i < n;i++)
            cnt[a[i]]++,cnt[b[i]]++;

        bool t = 1;

        for(int i = 0;i < K;i++){
            if(cnt[i]%2){
                t = 0;
            }
        }

        if(t){
            cout << "YES" << endl;
            vector<pari > d;

            for(int i = 0;i < n;i++){
                //cout << a << ' ' << b << endl;
                if(a[i] != b[i]){
                    t = 0;
                    for(int j = i+1;j < len(a);j++){
                        if(a[i] == a[j]){
                            t = 1;
                            d.push_back({j,i});
                            swap(a[j],b[i]);
                            break;
                        }
                    }
                    if(t) continue;

                    for(int j = i+1;j < len(b);j++){
                        if(b[i] == b[j]){
                            t = 1;
                            d.push_back({i,j});
                            swap(a[i],b[j]);
                            break;
                        }
                    }

                    if(t) continue;


                    for(int j = i+1;j < len(a);j++){
                        if(a[i] == b[j]){
                            t = 1;
                            d.push_back({j,j});
                            d.push_back({j,i});
                            swap(a[j],b[j]);
                            swap(a[j],b[i]);
                            break;
                        }
                    }

                    if(t) continue;

                    for(int j = i+1;j < len(a);j++){
                        if(a[j] == b[i]){
                            t = 1;
                            d.push_back({j,j});
                            d.push_back({i,j});
                            swap(a[j],b[j]);
                            swap(a[i],b[j]);
                            break;
                        }
                    }

                }
            }

            cout << len(d) << endl;
            for(pari i : d)
                cout << i.first+1 << ' ' <<  i.second+1 << endl;

        }else cout << "No" << endl;
    }

}

void solve(){

}

signed main(){
    volodya22();
    input();
    solve();
}
