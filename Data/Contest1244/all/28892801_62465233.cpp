#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i  = 0; i < t; i++){
        int a, b, c, d, k;
        cin>>a>>b>>c>>d>>k;
        int x = a/c;
        if(a%c != 0){
            x++;
        }
        int y = b/d;
        if(b%d != 0){
            y++;
        }

        if(x + y > k){
            cout<<-1<<endl;
        }
        else{
            cout<<x<<" "<<y<<endl;
        }

    }
    return 0;
}
