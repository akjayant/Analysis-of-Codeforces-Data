#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& a, int n) {
        sort(a.begin(), a.end());
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, min(i + 1, a[n - i - 1]));
        }
       return result;
    }
};

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; ++j)
            cin >> a[j];
        int result = Solution().solve(a, n);
        cout << result << endl;
    }
    return 0;
}