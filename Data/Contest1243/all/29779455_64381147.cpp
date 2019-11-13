#include <bits/stdc++.h>


#define mkp(i,j) make_pair(i,j)
#define int long long
#define _sz(x) (int)x.size()

using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
const int LOGMAX = 105;
const int inf = 1e9;
const int md = 1e9 + 7;
typedef pair < int , int > ii;


int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s,t; cin>>s>>t;
        vector<int> difs;
        for(int i = 0;i<n;i++){
            if(s[i] != t[i]){
                difs.push_back(i);
            }
        }
        if(_sz(difs)!=2){
            cout<<"NO"<<endl;
            continue;
        }
        int i = difs[0] , j = difs[1];
        if(s[i]==s[j] && t[j]==t[i]){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;

    }

    return 0;

}
