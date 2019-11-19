#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using LL = long long;

int main() {
        int N;
        cin >> N;
        auto nums = vector<LL>(N);
        for (int i = 0; i < N; i++) {
                cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        LL ll = 0, rr = 0;
        for (int i = 0; i < N / 2; i++) {
                ll += nums[i];
        }
        for (int i = N / 2; i < N; i++) {
                rr += nums[i];
        }
        cout << ll * ll + rr * rr << endl;
        return 0;
}