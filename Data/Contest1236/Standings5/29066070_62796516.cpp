#include <bits/stdc++.h>
//F6編譯，右上三角形執行，ctrl+c強制停止執行  F5開啟exe
#define ll long long
#define maxn 305
#define mod 1000000007
using namespace std;

int n;
vector<int> v[maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n * n; i++)
    {
        if ((i / n) % 2 == 0)
            v[i % n].push_back(i);
        else
            v[n - 1 - i % n].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", v[i][j] + 1);
        printf("\n");
    }

    return 0;
}