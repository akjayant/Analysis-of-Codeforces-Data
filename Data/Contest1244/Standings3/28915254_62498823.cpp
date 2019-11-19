// include stdc++.h slows down compilation much.
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

#define FAIL_RETURN \
do\
{\
    printf("-1\n");\
    return 0;\
} while(0);

const int N = 1e5 + 10;
ll a[N];

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }

    sort(a + 1, a + 1 + n);
    int left = 1;
    int right = n;
    int leftNum = 1;
    int rightNum = 1;
    ll ans = a[n] - a[1];
    while (left < right && k > 0)
    {
        if (leftNum < rightNum)
        {
            ll diff = a[left + 1] - a[left];
            if (diff * leftNum >= k)
            {
                a[left] += k / leftNum;
                k = 0;
                break;
            }
            k -= leftNum * diff;

            leftNum++;
            left++;
        }
        else
        {
            ll diff = a[right] - a[right - 1];
            if (diff * rightNum >= k)
            {
                a[right] -= k / rightNum;
                break;
            }
            k -= rightNum * diff;
            rightNum++;
            right--;
        }
    }

    ans = a[right] - a[left];
    printf("%lld\n", ans);
	
	return 0;
}
