#define pb push_back
#define mod 1000000009
#define ff first
#define ss second
#define maxn 100005
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;


int main(int argc, char const *argv[]) {
    int tc;
    cin >> tc;
    while(tc--){
        string s, t;
        vector<int> v;
        int n;
        cin >> n;
        cin >> s >> t;
        for(int i=0;i<n;i++){
            if(s[i] != t[i]){
                v.pb(i);
            }
        }
        if(v.size() == 0){
            cout << "Yes"<< endl;
            continue;
        }
        else if(v.size() == 2){
            int x,  y;
            x = v[0];
            y = v[1];
            if(s[x] == s[y] && t[x] == t[y]){
                cout << "Yes"<< endl;
            }
            else{
                cout <<"No"<< endl;
            }
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}
