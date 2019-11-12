#include <bits/stdc++.h>
using namespace std;
int n,q;
int a[100004];
int main()
{
    cin >>q;
    while (q--)
    {
        cin >>n;
        for (int i=0;i<n;i++)
        {
            cin >>a[i];;
        }
        sort(a,a+n);
        reverse(a,a+n);
        for (int i=0;i<n;i++)
        {
            if (i+1>a[i])
            {
                cout <<i<<'\n';
                goto ss;
            }
        }
        cout <<n<<'\n';
        ss:{}
    }
    return 0;
}
