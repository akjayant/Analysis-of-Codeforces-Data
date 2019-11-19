//Ima fall asleep
#include <iostream>
#define ll long long
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        int a[n];
        ll evena = 0;
        ll evenb = 0;
        for (int i = 0; i < n; i++) {cin >> a[i]; if(0 == a[i]%2){evena++;}}
        ll m;
        cin >> m;
        int b[m];
        for (int i = 0; i < m; i++) {cin >> b[i]; if(0 == b[i]%2){evenb++;}}
        cout << (evena*evenb) + (n-evena)*(m-evenb) << "\n";
    }
    return 0;
}