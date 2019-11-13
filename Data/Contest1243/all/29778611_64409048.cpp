#define pb push_back
#define mod 1000000009
#define ff first
#define ss second
#define maxn 100005
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

string s, t;
int n;
vector< pair<int, int> > res;

bool doTry(int x){
    for(int i=x+1;i<n;i++){
        if(s[i] == s[x]) {
            res.pb({i, x});
            swap(s[i], t[x]);
            return true;
        }
    }
    return false;
}

bool toTry(int x){

    int pos = -1, tos = n-1;
    for(int i=x+1;i<n;i++){
        if(t[i] == s[x]){
            pos = i;
            break;
        }
    }
    if(pos == -1) return false;
    for(int i=x+1;i<n;i++){
        if(s[pos] == s[i]){
            tos = i;
        }
    }
    swap(t[pos], s[tos]);
    res.pb({tos, pos});
    swap(s[tos], t[x]);
    res.pb({tos, x});
    return true;
}

int main(int argc, char const *argv[]) {
    int TC;
    cin >> TC;
    while(TC--){
        bool ok = true;
        int pp = 0;
        res.clear();
        cin >> n;
        cin >> s >> t;
        for(int i=0;i<n;i++){
            if(s[i] != t[i]){
                if(!doTry(i)){
                    if(!toTry(i) ){
                        ok = false;
                        break;
                    }
                }
            }
            else{
                pp = i;
            }
        }
        //cout << s << " "<< t << endl;
        if(s != t || (res.size() > (n+n)) ) ok = false;
        if(ok){
            cout << "Yes" << endl;
            if(res.empty())res.pb({pp, pp});
            cout << res.size() << endl;
            for(auto x : res){
                cout << (x.ff+1) << " " << (x.ss+1) << endl;
            }
        }
        else{
            cout << "No" << endl;
        }
        //cout << s << " "<< t << endl;
    }

    return 0;
}
