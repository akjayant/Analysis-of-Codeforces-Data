#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i <= (b);i++)
#define FORD(i,a,b) for (int i = (b); i >= (a);i--)
#define all(v) v.begin(),v.end()
#define REV(v) reverse(v.begin(),v.end())
#define INF 1e9
#define int long long
const int N = 1123456;

using namespace std;

inline long long read(){
    char c = getchar();
    long long t = 0, f = 1;
    while (!isdigit(c)) f = (c == '-') ? -1 : 1, c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    return t * f;
}
int a[500][500];
void solution(){
    int n;
    cin >> n;
    int res = 0;
    for (int j = 1; j <= n;j++){
        if(j % 2)
            for (int i = 1; i <= n;i++){
                a[i][j] = ++res;
            }
        else
            for (int i = n; i >= 1;i--){
                a[i][j] = ++res;
            }
    }
    for (int i = 1; i <= n;i++,cout << endl){
        for (int j = 1; j <= n;j++){
            cout << a[i][j] << " ";
        }
    }
}

int32_t main(){
    int t;
    t = 1;
    while(t--)
        solution();
}
