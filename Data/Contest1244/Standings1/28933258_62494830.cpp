#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int nums[100000];

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums, nums+n);
    int st = 0, ed = n-1;
    int ec = 0;
    ll ans = 0;
    while(k > 0 && st != ed)
    {
        if(st < ec)
        {
            ll inc = nums[st+1] - nums[st];
            st++;
            if(inc*st <= k)
                k -= inc*st;
            else
            {
                ans += k / st;
                st--;
                break;
            }
        }
        else
        {
            ll inc = nums[ed] - nums[ed-1];
            ec++;
            ed--;
            if(inc*ec <= k)
                k -= inc*ec;
            else
            {
                ed++;
                ans += k / ec;
                break;
            }
        }
    }
    cout << nums[ed] - nums[st] - ans;
    return 0;
}
