#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int main()
{
    int k, n;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        vector <int> a;

        cin >> n;

        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }

        sort(a.begin(), a.end());

        bool f = false;
        int ma = 1;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            ma = max(min(a[i], (int)a.size() - i), ma);
        }

        cout << ma << endl;


    }
    return 0;
}
