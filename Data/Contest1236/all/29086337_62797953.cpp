#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

const int INF = 0x3c3c3c3c;
const ll INF_L = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 309;

int arr[MAX_N][MAX_N];

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    int c = 1;
    for(int i = 1; i <= n; i++){
        if(i % 2){
            for(int j = 1; j <= n; j++){
                arr[j][i] = c;
                c++;
            }
        }else{
            for(int j = n; j >= 1; j--){
                arr[j][i] = c;
                c++;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}