#include <bits/stdc++.h>
#define ll long long
#define lf long double
#define INF 1000000000
#define MAX 100001
#define M 1000000007
using namespace std;

int n;
string s, temp;

int findPartition() {
    int extra = 0;
    int open = 0;
    for (int i=0;i<n;i++) {
        if (temp[i]=='(') open++;
        else {
            if (open) open--;
            else extra++;
        }
    }
    int idx = n-1;
    while (idx>=0) {
        if (extra==0) return idx;
        if (temp[idx]=='(') extra--;
        else extra++;
        idx--;
    }
    return 0;
}

int fixString(int idx) {
    string tt = "";
    for (int i=idx+1;i<n;i++) tt+=temp[i];
    for (int i=0;i<=idx;i++) tt+=temp[i];
    temp = tt;
    // cout << temp << endl;
    return 0;
}

int findAllCorrect() {
    int total = 0;
    int open = 0;
    for (int i=0;i<n;i++) {
        if (temp[i]=='(') open++;
        else {
            open--;
            if (!open) total++;
        }
    }
    return total;
}

int main() {
    cin >> n;
    cin >> s;
    int open = 0;
    for (int i=0;i<n;i++) {
        if (s[i]=='(') open++;
        else open--;
    }
    if (open) {
        cout << 0 << endl;
        cout << "1 1" << endl;
        return 0;
    }
    int mx = 0, l=1, r=1;
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            temp = s;
            swap(temp[i], temp[j]);
            fixString(findPartition());
            int k = findAllCorrect();
            if (k>mx) {
                mx = k;
                l = i+1;
                r = j+1;
            }
        }
    }
    cout << mx << endl;
    cout << l << " " << r << endl;
    return 0;
}