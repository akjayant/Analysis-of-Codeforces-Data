#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

using namespace std;
const int maxn=1e5+10;
int a[maxn];
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int l=1,r=1000+10;
        while((r-l)>1){
            int mid=(l+r) >> 1;
            int temp=0;
            for(int i=0;i<n;i++){
                if(a[i]>=mid) temp++;
            }
            if(temp>=mid){
                l=mid;
            }
            else r=mid;
        }
        cout << l << endl;
    }


    return 0;
}
