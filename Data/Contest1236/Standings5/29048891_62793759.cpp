#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

signed main(){
    int n;
    
    cin >> n;
    
    int mat[n+5][n+5], p = 1, cnt = 1;
    
    for(int i = 1; i <= n; i++){
          if(p){
              for(int j = 1; j <= n; j++){
                  mat[j][i] = cnt++;
              }
          }
          else{
              for(int j = n; j >= 1; j--){
                  mat[j][i] = cnt++;
              }
          }
          p^=1;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }
}