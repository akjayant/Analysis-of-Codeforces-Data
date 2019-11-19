#include<bits/stdc++.h>

using namespace std;

long long n, k, a[100010];
int main()
{
    cin >> n >> k;
    long long i, j;
    for (i = 0; i < n; i ++)
        cin >> a[i];

    sort(a, a + n);
    /**for (i = 0; i < n; i ++)
        cout << a[i] << " ";
    cout << endl;*/
    ///cout << "-------------------" << endl;
    i = 0;
    j = n - 1;
    while(i < j)
    {

        while(i < n - 1 && a[i] == a[i + 1])
            i ++;
        while(j > 0 && a[j] == a[j - 1])
            j --;

        ///cout << i << " " << j << " " << k << endl;
        if (i < j)
        {
            if (i + 1 < n - j)
            {
                long long p = i + 1;
                long long best = k / p;
                if (best < a[i + 1] - a[i])
                {
                    cout << a[j] - (a[i] + best) << endl;
                    return 0;
                }
                k = k - p * (a[i + 1] - a[i]);
                i ++;
            }
            else
            {
                long long p = n - j;
                long long best = k / p;
                if (best < a[j] - a[j - 1])
                {
                    cout << (a[j] - best) - a[i] << endl;
                    return 0;
                }
                k = k - p * (a[j] - a[j - 1]);
                j --;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
/*
7 10
3 3 5 8 8 10 12
*/
