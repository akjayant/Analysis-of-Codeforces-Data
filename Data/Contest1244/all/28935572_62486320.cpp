#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define trav(a,b)   for(auto& a : (b))
#define debug(x)    clog << #x << " = " << x << endl;
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    //content
    ull n, k; cin >> n >> k;
    map<ull, ull> nums;
    rep(i,n) {
        ull u; cin >> u;
        nums[u]++;
    }
    while (k > 0 && nums.size() > 1) {
        ull numLowest = nums.begin()->second;
        ull numHighest = prev(nums.end())->second;
        if (numLowest < numHighest) {
            ull a = nums.begin()->first;
            ull b = next(nums.begin())->first;
            ull n = numLowest * (b - a);

            nums.erase(a);
            if (n > k) {
                ull len = k / numLowest;
                k = 0;
                nums.insert({a+len, 1});
            } else {
                k -= n;
                nums[b] += numLowest;
            }
        } else {
            ull a = prev(nums.end())->first;
            ull b = prev(prev(nums.end()))->first;
            ull n = numHighest * (a - b);

            nums.erase(a);
            if (n > k) {
                ull len = k / numHighest;
                k = 0;
                nums.insert({a - len, 1});
            } else {
                k -= n;
                nums[b] += numHighest;
            }
        }
    }
    if (nums.size() == 1) {
        cout << 0;
    } else {
        cout << prev(nums.end())->first - nums.begin()->first;
    }


    cout.flush();
    return 0;
}

