#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long int uLL;
typedef unsigned int uint;



int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string w;
        cin >> w;
        int idf = n, idl = -1;
        for(int i = 0; i < n; i++){
            if(w[i] == '1'){
                idl = i;
                if(i < idf){
                    idf = i;
                }
            }
        }
        int wyn = n;
        if(idf == n){
            cout << n << '\n';
            continue;
        }
        int dla1 = max(n+1, 2*(idl+1));
        int dlan = max(2*(n-idf), n+1);
        wyn = max(wyn, dla1);
        wyn = max(wyn, dlan);
        cout << wyn << '\n';
    }
    return 0;
}
