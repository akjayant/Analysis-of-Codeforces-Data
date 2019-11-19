#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        int a =0 ,b = 0,c= 0,d = 0;
        cin>>n;
        for(int i = 0;i<n;i++){
            int u;
            cin>>u;
            if(u%2 == 0) a++;
            else b++;
        }
        int m ;
        cin>>m;
        for(int i = 0;i<m;i++){
            int u;
            cin>>u;
            if(u%2 == 0) c++;
            else d++;
        }
        cout<<(long long)a*c+(long long)b*d<<endl;
    }
    return 0;
}
