#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,v[3];
        string s;
        cin >> n;
        for(int i = 0 ; i < 3 ; i += 1){
            cin >> v[i];
        }
        cin >> s;
        int g = 0;
        vector<char> ret(n,'F');
        for(int i = 0 ; i < n ; i += 1){
            if(s[i] == 'R'){
                if(v[1]){
                    g += 1;
                    v[1] -= 1;
                    ret[i] = 'P';
                }
            }else if(s[i] == 'P'){
                if(v[2]){
                    g += 1;
                    v[2] -= 1;
                    ret[i] = 'S';
                }
            }else{
                if(v[0]){
                    g += 1;
                    v[0] -= 1;
                    ret[i] = 'R';
                }
            }
        }
        if(g >= n/2 + (n%2==1)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0 ; i < n ; i += 1){
            if(ret[i] == 'F'){
                if(v[0]){
                    v[0] -= 1;
                    ret[i] = 'R';
                }else if(v[1]){
                    v[1] -= 1;
                    ret[i] = 'P';
                }else{
                    v[2] -= 1;
                    ret[i] = 'S';
                }
            }
        }
        for(char i : ret){
            cout << i;
        }cout << endl;
    }
}