#include <bits/stdc++.h>

using namespace std;

int value[100001];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> value[i];
    }
    long long up_size = 0, right_size = 0;
    sort(value, value + n);
    for(int i = 0; i < n / 2; i ++){
        up_size += value[i];
    }
    for(int i = n / 2; i < n; i ++){
        right_size += value[i];
    }
    cout << up_size * up_size + right_size * right_size;
}
