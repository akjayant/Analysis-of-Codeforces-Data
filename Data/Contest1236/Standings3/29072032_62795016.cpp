#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    int cnt = 1;
    for(int i = 0; i < n; ++i) {
        if(i%2 == 0) {
            for(int j = 0; j < n; ++j) {
                ans[j][i] = cnt++;
            }
        }else {
            for(int j = n-1; j >= 0; --j) {
                ans[j][i] = cnt++;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
