#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <unordered_map>
#include <string.h>
#include <math.h>
 
#define MAX_N 100005
#define f first
#define s second
 
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

int ar[MAX_N];
int N, M, T;
 
void solve() {
    cin >> N;
    
    string str;
    cin >> str;
    for (int i = 0; i < N; i ++)
        ar[i] = (str[i] - '0');
    
    int ans = 0;
    for (int i = 0; i < N; i ++) {
        ans = max(ans, max(N - i, (i + 1)) + (ar[i] == 1 ? max(N - i, (i + 1)) : 0));
    }
    
    cout << ans << endl;
    return;
}
 
int main() {
    cin >> T;
    
    for (int i = 0; i < T; i ++)
        solve();
    
    return (0);
}