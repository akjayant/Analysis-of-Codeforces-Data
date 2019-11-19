// in the name of holy satan
#include <bits/stdc++.h>
using namespace std;
const int mMain = 1100;

int n;
string s;

class Answer
{
public:
    int total;
    int l, r;
} ans;

int findAns()
{
    int opens = 0;
    int arr[mMain];
    int mn = 0;

    for (int i = 0; i < mMain; i++)
        arr[i] = 0;
    for (int i = 0; i < n; i++)
    {
        opens += (s[i] == '(' ? 1 : -1);
        arr[opens + 510]++;
        mn = min(opens, mn);
    }
    if (opens)
        return 0;
    return arr[mn + 510];
}
int main()
{
    iostream::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    ans.total = findAns();
    ans.l = 0;
    ans.r = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(s[i], s[j]);
            //* maxANS
            int curr = findAns();
            if (ans.total <= curr)
            {

                ans.total = curr;
                ans.l = i;
                ans.r = j;
            }
            swap(s[i], s[j]);
        }
    }
    cout << ans.total << '\n';
    cout << ans.l + 1 << ' ' << ans.r + 1;
}