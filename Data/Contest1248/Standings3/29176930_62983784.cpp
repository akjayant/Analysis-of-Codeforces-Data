#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector <long long> v(n);
    for (long long i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    long long up = 0, right = 0, p = 0;
    long long l = 0, r = v.size()-1;
    while(l != r)
    {
        if (p == 0)
        {
            right+=v[r]; r--;
            p = 1;
        }
        else
        {
            up+=v[l]; l++;
            p = 0;
        }
    }
    if (n % 2 == 0) up+=v[l];
    else right+=v[r];
    //cout << up << " " << right << endl;
    cout << up*up+right*right << endl;

    return 0;
}
