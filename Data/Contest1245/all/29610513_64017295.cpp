#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;

int t;

int n,nw;
int r1, p1, s1;
string ins;

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> n; 
        nw = n/2 + (n%2);
        cin >> r1 >> p1 >> s1;
        cin >> ins; 
        vector<char> out(ins.size());
        int ws = 0;
        for(int i = 0; i < n; i++){
            char g = ins[i];
            if(g == 'R'){
                if(p1 > 0){
                    out[i] = 'P'; p1--; ws++;
                }else out[i] = 0;
            }else if(g == 'P'){
                if(s1 > 0){
                    out[i] = 'S'; s1--; ws++;
                }else out[i] = 0;
            }else if(g == 'S'){
                if(r1 > 0){
                    out[i] = 'R'; r1--; ws++;
                }else out[i] = 0;
            }
        }
        if(ws < nw){
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            if(out[i] != 0)continue;
            if(r1 > 0){
                r1--; out[i] = 'R';
            }else if(p1 > 0){
                p1--; out[i] = 'P';
            }else if(s1 > 0){
                s1--; out[i] = 'S';
            }
        }
        cout << "YES" << endl;
        for(char c: out) cout << c;
        cout << endl;
    }
}
