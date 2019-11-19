/*
ID: Miminyte500
LANG: C++
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <utility>

using namespace std;

vector<long long> v;

int main()
{
    ios_base::sync_with_stdio(0);

    long long n, k;
    cin >> n >> k;

    v.resize(n);
    for(long long i=0;i<n;i++) cin >> v[i];

    sort(v.begin(), v.end());

    long long tst(0);

    for(long long i=0;i<n;i++) {
        tst+=abs(v[i]-v[n/2]);
    }

    if(tst <= k) {
        cout << 0;
        return 0;
    }

    long long totCost(0), moveCost(0);

    long long l, r, sa, sb;
    l=0;
    r=n-1;

    for(long long i=0;i<(n+4)/2;i++) {
//        while(v[l] == v[l+1]) l++;
//        while(v[r] == v[r-1]) r--;
        sa = l+1;
        sb = n-r;

        moveCost = sa * (v[l+1] - v[l]) + sb * (v[r] - v[r-1]);

        if(totCost + moveCost <= k) {
            l++;
            r--;
            sa = l+1;
            sb = r-1;
            totCost += moveCost;
            continue;
        }
        else {
            break;
        }
    }

    //cout << sa << ' ' << sb;

    if(sa * (v[l+1] - v[l]) > k - totCost) {
        cout << (v[r] - v[l]) - (k - totCost)/sa;
        return 0;
    }
    else {
        totCost += sa * (v[l+1] - v[l]);
        l++;

        cout << (v[r] - v[l]) - (k - totCost)/sb;
    }

    return 0;
}

/*
8 5
1 2 2 4 5 7 7 8
*/
