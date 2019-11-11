#include <iostream>
#include <tuple>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <iomanip>

using namespace std;


int main() {
    int n, m, t;
    vector<int> ar;
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        ar.resize(n, 0);
        for (int i = 0; i < n; ++i)
            ar[i] = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'R')
            {
                if (b != 0)
                {
                    ar[i] = 1;
                    b -= 1;
                    cnt += 1;
                }
            }
            if (s[i] == 'P')
            {
                if (c != 0)
                {
                    ar[i] = 1;
                    c -= 1;
                    cnt += 1;
                }
            }
            if (s[i] == 'S')
            {
                if (a != 0)
                {
                    ar[i] = 1;
                    a -= 1;
                    cnt += 1;
                }
            }
        }
        if (cnt >= (n + 1) / 2)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i)
            {
                if (ar[i] == 0)
                {
                    if (a != 0)
                    {
                        a -= 1;
                        cout << 'R';
                    }
                    else if (b != 0)
                    {
                        b -= 1;
                        cout << 'P';
                    }
                    else if (c != 0)
                    {
                        c -= 1;
                        cout << 'S';
                    }
                }
                else
                {
                    if (s[i] == 'R')
                    {
                        cout << 'P';
                    }
                    else if (s[i] == 'P')
                    {
                        cout << 'S';
                    }
                    else if (s[i] == 'S')
                    {
                        cout << 'R';
                    }
                }
            }
        }
        else
            cout << "NO";
        cout << endl;
    }
    
}
