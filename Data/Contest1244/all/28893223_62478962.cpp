#pragma region
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

inline ll pos_mod(ll i, ll n) {return (i % n + n) % n;}
#define FORI(n) for (int i=0;i<(n);i++)
#define FORJ(n) for (int j=0;j<(n);j++)
#define FORK(n) for (int k=0;k<(n);k++)
#define MOD 1000000007
#pragma endregion

vvi ADJ;vi indexes;

void dfs(int i, int p, int d){
    indexes[d]=i;
    for (int n:ADJ[i]){
        if (n!=p){
            dfs(n,i,d+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vvi C(3,vi(n)); FORI(n) cin>>C[0][i];
    FORI(n) cin>>C[1][i];
    FORI(n) cin>>C[2][i];

    ADJ=vvi(n);
    FORI(n-1){
        int a,b; cin>>a>>b; a--;b--;
        ADJ[a].push_back(b);
        ADJ[b].push_back(a);
    }

    int cnt2=0;
    int cnt1=0;
    int oneIndex=0;
    FORI(n){
        if (ADJ[i].size()==1){
            cnt1++; oneIndex=i;
        } 
        if (ADJ[i].size()==2) cnt2++;
    }
    if (cnt1!=2 || cnt2!=n-2){
        cout << -1; return 0;
    }
    indexes=vi(n);
    dfs(oneIndex,-1,0);

    vi bestC(n);
    vi currC(n);
    ll bestPrice=(ll)MOD*MOD;
    ll currPrice;
    vii confs{{0,1},{1,1},{2,1},{0,2},{1,2},{2,2}};
    for (ii conf:confs){
        currPrice=0;
        int currColor=conf.first;
        FORI(n){
            currPrice+=C[currColor][indexes[i]];
            currC[indexes[i]]=currColor;
            currColor=pos_mod((currColor+conf.second),3);
        }

        if (currPrice<bestPrice){
            bestPrice=currPrice;
            bestC=currC;
        }
    }
    cout << bestPrice << endl;
    FORI(n) cout << (bestC[i]+1) << " ";


}