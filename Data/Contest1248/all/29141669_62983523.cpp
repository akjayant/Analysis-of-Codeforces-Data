#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> sticks(n);
    for(int i=0;i<n;i++)
        cin >> sticks[i];
    sort(sticks.begin(),sticks.end());
    reverse(sticks.begin(), sticks.end());
    long long s1 = 0;
    long long s2 = 0;
    int st = (n+1)/2;
    for(int i=0;i<st;i++)
        s1+=sticks[i];
    for(int i=st;i<n;i++)
        s2+=sticks[i];
    cout << s1*s1 + s2*s2 << endl;
    return 0;

}
