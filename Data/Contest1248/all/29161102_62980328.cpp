#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
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

    int n;
    cin >> n;
    vector<long long> v;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int mid = n / 2;
    long long a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < mid)
            a += v[i];
        else
            b += v[i];
    }
    cout << a * a + b * b;




	return 0;
}
