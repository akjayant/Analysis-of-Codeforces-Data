#include<bits/stdc++.h>
using namespace std;
long long n, a[100005];
bool cmp(int a, int b){
    return b < a;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    long long summ;
    summ = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        summ += a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    long long t1, t2;
    t1 = t2 = 0;
    for(int i = 1; i <= (n + 1) / 2; i++){
        t1 += a[i];
    }
    t2 = summ - t1;
    cout<<t1 * t1 + t2 * t2<<endl;
}
