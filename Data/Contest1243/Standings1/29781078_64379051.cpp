#include<bits/stdc++.h>

#define LL long long
using namespace std;
const long long mod = 1000000000 + 7;


int a[2000];
int b[2000];
int main() {
    //freopen("C:\\Users\\93569\\Desktop\\untitled\\a.txt", "r", stdin);
//    freopen("s","r",stdin)
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++){
            cin>>a[i];
            b[a[i]]++;
        }

        for(int i=n-1;i>=0;i--){
            b[i]+=b[i+1];
        }
        for(int i=n; i>=0;i--){
            if(b[i]>=i){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}