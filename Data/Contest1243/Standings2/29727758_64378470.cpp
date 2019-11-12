#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        string s,t;
        cin >> n >> s >> t;
        
        int dif[n];
        memset(dif, 0, sizeof dif);
        int cont = 0, a=-1, b;
        for (int i=0; i<n; i++){
            if (s[i] != t[i]){
                dif[i] = 1;
                cont++;
                if (a!=-1) b = i;
                else a = i;
            }
        }
        if (cont != 2) cout << "No\n";
        else{
            if (s[a] == s[b] && t[b] == t[a]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}