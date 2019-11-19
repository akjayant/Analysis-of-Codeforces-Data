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
int T, A, B, C, D, K;
 
void solve() {
    cin >> A >> B >> C >> D >> K;
    
    for (int i = 0; i <= 100; i ++) {
        for (int j = 0; j <= 100; j ++) {
            if (i + j <= K) {
                if (C * i >= A && j * D >= B) {
                    cout << i << " " << j << endl;
                    return;
                }
            }
        }
    }
    
    cout << "-1" << endl;
    return;
}
 
int main() {
    cin >> T;
    
    for (int i = 0; i < T; i ++)
        solve();
    
    return (0);
}