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


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {

                cnt++;
                v.push_back(i);
            }
        }
        if (cnt == 0)
            cout << n;
        else if (cnt == 1)
            cout << max(2 * (v[0] + 1), 2 * (n - v[0]));
        else
        {
            int ans1 = max(2 * (v[0] + 1), 2 * (n - v[0])), ans2 = max(2 * (v.back() + 1), 2 * (n - v.back()));
            cout << max(ans1, ans2);
        }
        cout << "\n";
    }



	return 0;
}
