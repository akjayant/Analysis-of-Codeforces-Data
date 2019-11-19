#include <bits/stdc++.h>
using namespace std;
#define im 2147483647
#define lm 9223372036854775807
#define ll long long
#define vb vector<bool>
#define vi vector<int>
#define vl vector<long long>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define ff first
#define ss second
#define _graph map<int, vector<int>>
#define lower_str(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define upper_str(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define debug(index, num) cout << "Case #" << index << ": " << num << endl
#define nmax(an, na) an = max(an, na)
#define nmin(an, na) an = min(an, na)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep2(i, a, b) for (int i = a; i <= b; i++)
#define repp(i, a, b) for (int i = a; i >= b; i--)
#define repp2(i, a, b) for (int i = a-1; i >= b; i--)
#define be(x) x.begin(), x.end()
#define rbe(x) x.rbegin(), x.rend()
#define pb push_back
#define IO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
map<pair<int,int>,int> mapper;
set<int> sett;
void DFS(int curr){
    vi v;
    for(int i : sett){
        if(mapper[{curr,i}] == 0){
            v.push_back(i);
        }
    }
    for(int a : v){
        sett.erase(a);
    }
    for(int a : v){
        DFS(a);
    }
}

int main(){
    IO; 
    int n, m, t1, t2, ans = 0;
    cin >> n >> m;
    rep2(i, 1, n){
        sett.insert(i);
    }
    rep(i, 0, m) {
        cin >> t1 >> t2;
        mapper[{t1,t2}] = 1;
        mapper[{t2,t1}] = 1;
    }
    rep2(i, 1, n) {
        if(!sett.empty()){
            int s = *sett.begin();
            sett.erase(s);
            DFS(s);
            ans++;
        }
        else break;
    }
    cout << ans-1;
    return 0;
}