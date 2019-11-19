#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int first = -1, last = -1;
        for(int i = 0; i < n; i++)
            if(s[i] == '1')
            {
                if(first == -1)
                    first = i;
                last = i;
            }
        int left, right;
        left = first;
        right = n - last - 1;
        if (first == -1)
            cout << n << "\n";
        else
            cout << max(n * 2 - left * 2, n * 2 - right * 2) << "\n";
    }
    return 0;
}
