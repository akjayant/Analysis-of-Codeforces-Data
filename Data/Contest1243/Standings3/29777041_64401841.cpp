#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int,int> f[120];
int n,cnt;
string a,b;
int text(int x)
{
    for (int i=x;i<n;i++){
        if(a[i]==a[x-1]){
            swap(a[i],b[x-1]);
            f[cnt].first=i+1;
            f[cnt++].second=x;
            return 1;
        }
        if(b[i]==a[x-1]){
            swap(a[i],b[i]);
            f[cnt].first=i+1;
            f[cnt++].second=i+1;
            swap(b[x-1],a[i]);
            f[cnt].first=i+1;
            f[cnt++].second=x;
            return 1;
        }
    }
    return 0;
}
int main()
{
    std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        cin >> n;
        cin >> a >> b;
        cnt=0;
        int flag=0;
        for (int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(!text(i+1)){
                    flag=1;
                    break;
                }
            }
        }
        if(flag) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << cnt << endl;
            for (int i=0;i<cnt;i++){
                cout << f[i].first << " " << f[i].second << endl;
            }
        }
    }
    return 0;
}
