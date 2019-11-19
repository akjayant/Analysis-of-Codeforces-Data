//Ima fall asleep
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main()
{
    int n; cin >> n;
    int sticks[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) {cin >> sticks[i]; sum += sticks[i];}
    sort(sticks, sticks+n);
    ll xsum = 0, ysum = 0;
    for (int i = 0; i < n/2; i++) {xsum += sticks[i];}
    ysum = sum - xsum;
    cout << xsum*xsum + ysum*ysum << "\n";
    return 0;
}