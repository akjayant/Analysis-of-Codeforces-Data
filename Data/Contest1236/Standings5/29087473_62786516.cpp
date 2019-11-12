#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i <= (b);i++)
#define FORD(i,a,b) for (int i = (b); i >= (a);i--)
#define all(v) v.begin(),v.end()
#define REV(v) reverse(v.begin(),v.end())
#define INF 1e9
//#define int long long
const int N = 1123456;

using namespace std;

inline long long read(){
    char c = getchar();
    long long t = 0, f = 1;
    while (!isdigit(c)) f = (c == '-') ? -1 : 1, c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    return t * f;
}

void solution(){
    int x,y,z,cnt = 0;
    cin >> x >> y >> z;
    int a = min(z / 2,y);
    cnt = cnt + 3 * a;
    y -=a;
    a = min(y / 2,x);
    cnt = cnt +  3 * a;
    cout << cnt << endl;
}

int32_t main(){
    int t;
    t = read();
    while(t--)
        solution();
}
