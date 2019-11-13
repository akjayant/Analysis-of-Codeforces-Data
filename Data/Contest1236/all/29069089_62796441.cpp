#include<bits/stdc++.h>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mod 1000000007
#define INF 1e18
#define ALPHABET_SIZE 26


using namespace std;
typedef long long ll;

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/


vector<int> sim[305];

int main(){
    int n; cin >> n;

    int tamb = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            tamb++;
            if(i % 2 == 0){
                sim[j].pb(tamb);
            }else{
                sim[n - j + 1].pb(tamb);
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = i + 1; j <= n; j++){
    //         int nyak1 = 0, nyak2 = 0;
    //         for(int k = 0; k < n; k++){
    //             for(int l = 0; l < n; l++){
    //                 if(sim[i][k] < sim[j][l]){
    //                     nyak1++;
    //                 }else{
    //                     nyak2++;
    //                 }
    //             }
    //         }
    //         // cout << i << " " << j << " " << nyak1 << "\n";
    //         // cout << j << " " << i << " " << nyak2 << "\n";
    //     }
    // }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n; j++){
            if(j != 0) cout << " ";
            cout << sim[i][j];
        }
        cout << "\n";
    }

}
