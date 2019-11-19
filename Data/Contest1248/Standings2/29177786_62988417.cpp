#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, a[100001];
long long x, y;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1,a + 1 + n);
    for(int i = 1; i <= n / 2; i ++)
    {
        y += a[i];
        x += a[n - i + 1];
    }
    if(n % 2 != 0)
        x += a[n - n / 2];
    cout << x * x + y * y;
}