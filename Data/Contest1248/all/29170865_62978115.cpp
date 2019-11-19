#include <bits/stdc++.h>
#define ll long long
#define forin for(int i=0;i<n;i++)
#define forjn for(int j=0;j<n;j++)
#define forjm for(int j=0;j<m;j++)
using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q){
            q--;
        ll n;
        cin>>n;
        ll cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        forin{
            int x;
            cin>>x;
            if(x%2)
                cnt1++;
            else
                cnt2++;
        }
        int m;
        cin>>m;
        forjm{
            int x;
            cin>>x;
            if(x%2)
                cnt3++;
            else
                cnt4++;
        }
        cout<<cnt1*cnt3+cnt2*cnt4<<endl;
    }
    return 0;
}
