#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <bitset>
using namespace std;







int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    long long k;
    int n;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >>  v[i];
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    while (true)
    {
        if (i >= j)
        {
            cout << 0;
            return 0;
        }
        if (i + 1 <= n - j)
        {
            long long d = v[i + 1] - v[i];
            if (d * (i + 1) >= k)
            {
                long long temp = k / (i + 1);
                cout << v[j] - v[i] - temp;
                return 0;
            }
            else
            {
                k -= d * (i + 1);
                i++;
            }
        }
        else
        {
            long long d = v[j] - v[j - 1];
            if (d * (n - j) >= k)
            {
                long long temp = k / (n - j);
                cout << v[j] - v[i] - temp;
                return 0;
            }
            else
            {
                k -= d * (n - j);
                j--;
            }
        }
    }

	return 0;
}
