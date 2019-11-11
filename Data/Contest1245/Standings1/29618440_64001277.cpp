#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

char beat(char c){
    if(c == 'P') return 'S';
    if(c == 'R') return 'P';
    return 'R';
}
int idx(char c){
    if(c == 'R') return 0;
    if(c == 'P') return 1;
    return 2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, h[3];
        string bob;
        cin >> n >> h[0] >> h[1] >> h[2] >> bob;
        string alice(n, ';');
        int won = 0;
        for(int i = 0 ; i < n ; i++){
            if(h[idx(beat(bob[i]))] == 0) continue;
            h[idx(beat(bob[i]))]--;
            alice[i] = beat(bob[i]);
            won++;
        }
        if(won * 2 < n){
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0 ; i < n ; i++){
            if(alice[i] == ';'){
                if(h[0]){
                    alice[i] = 'R';
                    h[0]--;
                }
                else if(h[1]){
                    alice[i] = 'P';
                    h[1]--;
                }
                else if(h[2]){
                    alice[i] = 'S';
                    h[2]--;
                }
            }
        }
        cout << "YES" << endl << alice << endl;
    }
}
