#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> c;
vector<long long> minans;
long long mians;

void getAns(vector<long long>& arr, long long c1, long long c2)
{
    long long ans = 0;
    ans = c[c1][arr[0]] + c[c2][arr[1]];
    long long c3 = 3 - c1 - c2;
    for (long long i = 2; i < arr.size(); i++) {
        if (i % 3 == 0) {
            ans += c[c1][arr[i]];
        }
        if (i % 3 == 1) {
            ans += c[c2][arr[i]];
        }
        if (i % 3 == 2) {
            ans += c[c3][arr[i]];
        }
    }
    if (mians > ans)
    {
        mians = ans;
        for (long long i = 0; i < arr.size(); i++) {
            if (i % 3 == 0) {
                minans[arr[i]] = c1 + 1;
            }
            if (i % 3 == 1) {
                minans[arr[i]] = c2 + 1;
            }
            if (i % 3 == 2) {
                minans[arr[i]] = c3 + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    minans.resize(n);
    mians = 1e16;
    c.resize(3, vector<long long> (n));
    for (long long i = 0; i < n; i++) {
        cin >> c[0][i];
    }
    for (long long i = 0; i < n; i++) {
        cin >> c[1][i];
    }
    for (long long i = 0; i < n; i++) {
        cin >> c[2][i];
    }
    vector<vector<long long>> matrix(n);
    for (long long i = 0; i < n - 1; i++) {
        long long x, y;
        cin >> x >> y;
        matrix[x - 1].push_back(y - 1);
        matrix[y - 1].push_back(x - 1);
    }
    long long v = -1;
    for (long long i = 0; i < n; i++) {
        if (matrix[i].size() > 2) {
            cout << -1;
            return 0;
        }
        if (matrix[i].size() == 1) {
            v = i;
        }
    }
    vector<long long> arr;
    while (true) {
        arr.push_back(v);
        if (arr.size() == 1) {
            v = matrix[v][0];
        }
        else {
            if (matrix[v].size() == 1) break;
            else {
                if (matrix[v][0] == arr[arr.size() - 2]) {
                    v = matrix[v][1];
                }
                else {
                    v = matrix[v][0];
                }
            }
        }
    }
    getAns(arr, 0, 1);
    getAns(arr, 0, 2);
    getAns(arr, 1, 0);
    getAns(arr, 1, 2);
    getAns(arr, 2, 0);
    getAns(arr, 2, 1);
    cout << mians << endl;
    for (long long u : minans) cout << u << ' ';
    return 0;
}
