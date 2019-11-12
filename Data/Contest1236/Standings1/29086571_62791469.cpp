#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define ii pair<int,int>
#define mp make_pair
using namespace std;
int n;
int a[500][500];
int main()
{
    cin>>n;
    int cnt = 1;
    int ok = 1;
    for(int j=0;j<n;j++)
    {
        ok = !ok;
        if(!ok)
        {
            for(int i=0;i<n;i++)
            {
                a[i][j] = cnt;
                cnt++;
            }
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                a[i][j] = cnt;
                cnt++;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}
