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
        int a, b, c;
        cin >> a >> b >> c;

        int ans = min(c/2,b);
        
        c -= ans*2;
        b -= ans;
        
        int ans2 = min(b/2, a);
        cout << ans*3 + ans2*3 << endl;
    }
}
