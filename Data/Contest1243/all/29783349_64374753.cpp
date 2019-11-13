#include <iostream>

using namespace std;

int main()
{
    int k;

    cin >> k;

    for (int i = 1; i <= k; i++)
    {
        int n;

        cin >> n;

        int a[1009];
        int db[1009];

        for (int i = 1; i <= 1000; i++)
            db[i] = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            for (int j = 1; j <= a[i]; j++) db[j]++;
        }

        int ma = 0;

        for (int i = 1; i <= 1000; i++)
        {
            if (db[i] >= i) ma = i;
        }

        cout << ma << endl;
    }
}
