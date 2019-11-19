#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int n;
    vector<int> a;
    cin >> n;
    a.assign(n, 0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    long long x = 0, y = 0;
    for(int i=0;i<n;i++){
        if(i < (n+1) / 2)x += a[i];
        else y += a[i];
    }
    cout << x*x + y*y << endl;
}
