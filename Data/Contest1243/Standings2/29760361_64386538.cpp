#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
   int q;cin >> q;
  while(q--){
    int n;cin >> n;
    string s, t;
    cin >> s >> t;
    map<char, int> count;
    FOR(i, n){
        count[s[i]]++;
        count[t[i]]++;
    }
    bool done =false;
    for(auto val: count){
        if(val.second % 2){
            cout << "No" <<endl;
            done = true;
            break;
        }
    }
    if(done)continue;
    vector<pii> edges;
    FOR(i, n){
        if(s[i] == t[i]){
            continue;
        }
        int pos =  -1;
        int pos2 = -1;
        for(int j = i+1; j < n; j++){
            if(s[j] == s[i] && pos == -1){
                pos = j; 
            }
            if(t[j] == s[i] && pos2 == -1){
                pos2 = j;
            }
        }

        if(pos != -1){
            swap(t[i], s[pos]);
            edges.pb(mp(pos+1, i+1));
            continue;
        }
        if(pos2 != -1){
            swap(t[pos2], s[pos2]);
            swap(s[pos2], t[i]);
            edges.pb(mp(pos2 + 1, pos2+ 1));
            edges.pb(mp(pos2+ 1, i+1));
        }
    }
    cout << "Yes" <<endl;
    cout << edges.size() <<endl;
    for(auto val: edges)
        cout << val.first << " " << val.second <<endl;
  } 
}


