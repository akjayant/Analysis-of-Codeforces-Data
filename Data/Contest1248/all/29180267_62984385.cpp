#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define mp make_pair
#define ii pair<long long, long long>
#define MOD 998244353LL

int n;
ll arr[100005];

int main()
{
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        ll sum1, sum2;
        sum1 = sum2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(i < n / 2)
                sum1 += arr[i];
            else
                sum2 += arr[i];
        }
        cout << sum1 * sum1 + sum2 * sum2 << endl;
    }
    return 0;
}
