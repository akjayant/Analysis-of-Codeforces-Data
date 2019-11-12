#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

typedef long long ll;
using namespace std;
const int maxn = 1e6 + 5;
int a[500][500];
int main()
{
    int n;
    cin>>n;
    int cnt = n*n;
    for(int i = 1; i <= n; i++){
        if(i%2==1){
            for(int j = 1; j <= n; j++){
                a[i][j] = cnt--;
            }
        }else{
            for(int j = n; j >= 1; j--){
                a[i][j] = cnt--;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j == n)cout<<a[j][i]<<endl;
            else cout<<a[j][i]<<' ';
        }
    }
    return 0;
}
