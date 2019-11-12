#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define max(a,b) (a>b?a:b)
#define M 1000000007
#define N 1003
#define ll long long
#define f first
#define s second
using namespace std;
vector<pair<ll, ll>>r;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, m, i, x, j;
    char temp;
    string a, b;
    bool g;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        r.clear();
        for(i=0; i<n; ++i){
            g=0;
            for(j=i+1; j<n && !g; ++j)
                if(a[i]==a[j]){
                    r.push_back({j,i});
                    temp=a[j];
                    a[j]=b[i];
                    b[i]=temp;
                    g=1;
                }
            for(j=i+1; j<n && !g; ++j)
                if(a[i]==b[j]){
                    r.push_back({j,j});
                    temp=a[j];
                    a[j]=b[j];
                    b[j]=temp;
                    r.push_back({j,i});
                    temp=a[j];
                    a[j]=b[i];
                    b[i]=temp;
                    g=1;
                }
        }
        if(a==b){
            cout<<"Yes\n"<<r.size()<<"\n";
            for(auto it:r)
                cout<<it.f+1<<" "<<it.s+1<<"\n";
        }
        else cout<<"No\n";
    }
    return 0;
}