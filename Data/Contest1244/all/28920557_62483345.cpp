#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <numeric>
#define ll long long
#define MAXN 100000
using namespace std;

ll A[MAXN+2];
ll FCS[MAXN+2];

ll Solve(int n, ll k) {
    FCS[n+1]=0;
    for(int i=n;i>=1;i--) {
        FCS[i]=FCS[i+1]+A[i];
    }
    ll ans = A[n]-A[1];
    ll cumul_sum = 0;
    for(int i=1;i<=n-1;i++) {
        cumul_sum += A[i];
        ll left = k - (i*A[i]-cumul_sum);
        if (left < 0)
            break;
        ll minval = A[i];
        // smallest j >= i+1 such that FCS[j]-(n-j+1)*A[j] <= left
        int low=i+1;
        int high=n;
        while(low < high) {
            int mid = (low + high)/2;
            if (FCS[mid]-(n-mid+1)*A[mid] > left) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        left -=  (FCS[low]-(n-low+1)*A[low]);
        ll maxval = max(A[low-1], A[low] - left / (n-low+1));
        ans = min(ans, maxval - minval);
    }
    return ans;
}


int main() {
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    sort(A+1,A+n+1);
    ll ans1 = Solve(n,k);
    for(int i=1;i<=n;i++) {
        A[i]=A[n]-A[i];
    }
    sort(A+1,A+n+1);
    ll ans2 = Solve(n,k);
    cout << min(ans1, ans2) << endl;
}
