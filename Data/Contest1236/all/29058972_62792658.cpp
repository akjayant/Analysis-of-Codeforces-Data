#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

int main()
{
    if (fopen("data.in", "r"))
        freopen("data.in", "r", stdin);
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= N*N; j += N) {
            if ((j / N) % 2) cout << j+N-1-i << " ";
            else cout << j+i << " ";
        }
        cout << endl;
    }
}
