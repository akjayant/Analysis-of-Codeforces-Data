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
    int diffs = 0;
    vector<int> d;
    FOR(i, n){
        if(s[i] != t[i]){
            d.pb(i);
        }
    }
    if(d.size() > 2 || d.size() == 1){
        cout << "No" <<endl;
    }else{
       int i = d[0];
      int j = d[1];
      if(s[i] == s[j] && t[i] == t[j]){
        cout << "Yes" <<endl;
      }else cout << "No" <<endl; 
    
    }
  } 
}


