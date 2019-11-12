#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

typedef long long ll;
using namespace std;
const int maxn = 1e6 + 5;

int main()
{
//    freopen("a","r", stdin);
    int t;
    cin>>t;
    while(t--){
        int ans = 0;
        int a,b,c;
        cin>>a>>b>>c;
        for(int x = 0; x<=a;x++){
            for(int y = 0; y<=c/2; y++){
                if(2*x+y<=b)ans = max(ans, x+y);
            }
        }
        cout<<ans*3<<endl;
    }
    return 0;
}
