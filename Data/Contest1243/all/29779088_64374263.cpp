#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define ull unsigned long long
#define stop return cout << -1 << endl, false;

using namespace std;

int niz[262146];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector <int> niz(n);
        for(int i=0;i!=n;i++)
        {
            cin>>niz[i];
        }
        sort(niz.begin(),niz.end());

        int M=1;

        for(int i=n-1;i>=0;i--)
        {
            M = max(min(n-i, niz[i]),M);

        }
        cout<<M<<endl;
    }



    return 0;
}
