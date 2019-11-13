// ContestCoding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using ll = long long;

using namespace std;

int main()
{
    int q;
    cin >> q;
    for (auto i = 0; i < q; ++i)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s;
        cin >> t;

        vector<int> poses;
        auto could = true;

        for (auto j = 0; j < n; ++j)
        {
            if (s[j] != t[j])
                poses.emplace_back(j);
            if (poses.size() > 2)
                break;
        }
        if (poses.size() != 2)
            could = false;
        else
        {
            if (s[poses.front()] == s[poses.back()] && t[poses.front()] == t[poses.back()])
                could = true;
            else
                could = false;
        }

        if (could)
            cout << "Yes";
        else
            cout << "No";

        if (i < q - 1)
            cout << "\n";
    }
}
