#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 500;
int mapa[maxn][maxn];

int main()
{
    int n;
    while(cin >> n) {
        int tot = 1;
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 1) {
                for(int j = 1; j <= n; j++) {
                    mapa[j][i] = tot++;
                }
            }
            else {
                for(int j = n; j >= 1; j--) {
                    mapa[j][i] = tot++;
                }
            }
            
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << mapa[i][j] ;
                if(j != n) cout << ' ';
            }
            cout << endl;
        }
    }
}