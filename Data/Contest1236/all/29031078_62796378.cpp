#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define pll pair <ll, ll>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j % 2 == 0) cout << j * N + i << ' ';
            else cout << j * N + N - (i - 1) << ' ';
        }
        cout << '\n';
    }


}
