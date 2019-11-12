#include <bits/stdc++.h>

using namespace std;


int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int k;
    cin >> k;
    for(int j=0;j<k;j++)
    {
        int n;
        cin >> n;
        vector<int> x(n);
        for(int i=0;i<n;i++)
            cin >> x[i];
        sort(x.begin(),x.end());
        reverse(x.begin(),x.end());
        int i;
        for(i=0;i<n;i++)
        {
            if(x[i] < i+1)
              break;
        }
        cout << i << '\n';
    }

    return 0;
}
