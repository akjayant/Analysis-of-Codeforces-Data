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


int c1[100011], c2[100011], c3[100011];




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c1[i];

    for (int i = 0; i < n; i++)
        cin >> c2[i];

    for (int i = 0; i < n; i++)
        cin >> c3[i];

    vector<vector<int> > v(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }

    int ver = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i].size() > 2)
        {
            cout << -1;
            return 0;
        }
        if (v[i].size() == 1)
            ver = i;
    }
    vector<int> vec;
    vec.push_back(ver);
    int prev = ver;
    ver = v[ver][0];
    vec.push_back(ver);
    while (vec.size() < n)
    {
        int a = v[ver][0], b = v[ver][1];
        if (a == prev)
            swap(a, b);
        vec.push_back(a);
        prev = ver;
        ver = a;
    }

    long long ans = 0;
    vector<int> vans(n);

    for (int i = 0; i < n; i++)
    {
        int ver = vec[i];
        if (i % 3 == 0)
        {
            ans += c1[ver];
            vans[ver] = 1;
        }
        else if (i % 3 == 1)
        {
            ans += c2[ver];
            vans[ver] = 2;
        }
        else
        {
            ans += c3[ver];
            vans[ver] = 3;
        }
    }

    long long tempans = 0;
    vector<int> tempvans(n);
    for (int i = 0; i < n; i++)
    {
        int ver = vec[i];
        if (i % 3 == 0)
        {
            tempans += c1[ver];
            tempvans[ver] = 1;
        }
        else if (i % 3 == 1)
        {
            tempans += c3[ver];
            tempvans[ver] = 3;
        }
        else
        {
            tempans += c2[ver];
            tempvans[ver] = 2;
        }
    }
    if (tempans < ans)
    {
        ans = tempans;
        vans = tempvans;
    }

    tempans = 0;
    for (int i = 0; i < n; i++)
    {
        int ver = vec[i];
        if (i % 3 == 0)
        {
            tempans += c2[ver];
            tempvans[ver] = 2;
        }
        else if (i % 3 == 1)
        {
            tempans += c1[ver];
            tempvans[ver] = 1;
        }
        else
        {
            tempans += c3[ver];
            tempvans[ver] = 3;
        }
    }
    if (tempans < ans)
    {
        ans = tempans;
        vans = tempvans;
    }

    tempans = 0;
    for (int i = 0; i < n; i++)
    {
        int ver = vec[i];
        if (i % 3 == 0)
        {
            tempans += c2[ver];
            tempvans[ver] = 2;
        }
        else if (i % 3 == 1)
        {
            tempans += c3[ver];
            tempvans[ver] = 3;
        }
        else
        {
            tempans += c1[ver];
            tempvans[ver] = 1;
        }
    }
    if (tempans < ans)
    {
        ans = tempans;
        vans = tempvans;
    }

    tempans = 0;
    for (int i = 0; i < n; i++)
    {
        int ver = vec[i];
        if (i % 3 == 0)
        {
            tempans += c3[ver];
            tempvans[ver] = 3;
        }
        else if (i % 3 == 1)
        {
            tempans += c1[ver];
            tempvans[ver] = 1;
        }
        else
        {
            tempans += c2[ver];
            tempvans[ver] = 2;
        }
    }
    if (tempans < ans)
    {
        ans = tempans;
        vans = tempvans;
    }


    tempans = 0;
    for (int i = 0; i < n; i++)
    {
        int ver = vec[i];
        if (i % 3 == 0)
        {
            tempans += c3[ver];
            tempvans[ver] = 3;
        }
        else if (i % 3 == 1)
        {
            tempans += c2[ver];
            tempvans[ver] = 2;
        }
        else
        {
            tempans += c1[ver];
            tempvans[ver] = 1;
        }
    }
    if (tempans < ans)
    {
        ans = tempans;
        vans = tempvans;
    }


    cout << ans << "\n";
    for (auto it : vans)
    {
        cout << it << " ";
    }


	return 0;
}
