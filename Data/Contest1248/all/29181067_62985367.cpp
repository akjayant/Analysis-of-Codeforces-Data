/*
g++ -std=c++11 code.cpp; cat inp.txt | ./a.out
*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back

typedef long long int ll;

int arr[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr,arr+n);

    ll sumx = 0, sumy = 0;
    for(int i=n-1; i>=n/2; i--)
        sumx += arr[i];
    
    for(int i=n/2-1; i>=0; i--)
        sumy+= arr[i];

    cout << sumx*sumx + sumy*sumy << endl;
}