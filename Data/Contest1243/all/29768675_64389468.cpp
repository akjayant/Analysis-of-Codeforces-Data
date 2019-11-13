#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define sz size()
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
const int M=1005;
int mark[M];
int32_t main()
{
    int k; cin>>k;
    while(k--){
        fill(mark,mark+M,0);
        int n; cin>>n;
        for(int i=0;i<n;i++){
            int x; cin>>x;
            mark[x]++;
        }
        for(int i=n;i;i--){
            mark[i]+=mark[i+1];
            if(mark[i]>=i){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
