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

vector<int> con[MAX_N];

int ar[MAX_N], col[MAX_N][3], vis[MAX_N], color[MAX_N], answer[MAX_N];
int N, M, T;

void solve() {
    cin >> N;
    
    for (int ii = 0; ii < 3; ii ++) 
        for (int i = 0; i < N; i ++)
            cin >> col[i][ii];
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        a --; b --;
        
        con[a].push_back(b);
        con[b].push_back(a);
    }
    
    for (int i = 0; i < N; i ++)
        if (con[i].size() > 2) {
            cout << "-1" << endl;
            return;
        }
    
    long long ans = MAX_N * 1000000000ll;
    
    for (int ii = 0; ii < N; ii ++) {
        if (con[ii].size() == 1) {
            for (int j = 0; j < 3; j ++)
                for (int k = 0; k < 3; k ++) {
                    if (j == k) { continue; }
                    
                    int node = ii;
                    long long cst = 0ll;
                    
                    for (int i = 0; i < N; i ++) {
                        vis[node] = true;

                              if (i % 3 == 0) {
                                    cst += col[node][j];
                                    color[node] = j;
                                } else if (i % 3 == 1) {
                                    cst += col[node][k];
                                    color[node] = k;
                                } else {
                                    cst += col[node][3 - j - k];
                                    color[node] = 3 - j - k;
                                }
                                
                        for (int jj = 0; jj < con[node].size(); jj ++) {
                            if (!vis[con[node][jj]]) {
                                node = con[node][jj]; 
                                break;
                            }
                        }
                    }
                    
                    for (int i = 0; i < N; i ++)
                        vis[i] = false;
                
                    if (cst < ans) {
                        ans = cst;
                        
                        for (int i = 0; i < N; i ++)
                            answer[i] = color[i] + 1;
                    }                    
                }
            
            break;
        }
    }
    
    cout << ans << endl;
    
    for (int i = 0; i < N; i ++)
        cout << answer[i] << " ";
        
    cout << endl;
    return;
}
 
int main() {
    T = 1;
    
    for (int i = 0; i < T; i ++)
        solve();
    
    return (0);
}