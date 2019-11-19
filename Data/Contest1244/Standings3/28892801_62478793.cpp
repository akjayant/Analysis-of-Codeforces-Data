#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    long long n, p, w, d;
    cin>>n>>p>>w>>d;

    long long gcd = __gcd(w, d);
        int yes = 0;
        long long y = 0;
        long long x = 0;
        for(long long i = 0; i < w; i++){
            if((p - d*i >= 0) && (p - d*i)%w == 0){
                x = (p - d*i)/w;
                y = i;
                if(x + y <=n){
                    yes = 1;
                    break;
                }

            }
        }

        if(yes == 1){
            cout<<x<<" "<<y<<" "<<n - x - y;
        }
        else{
            cout<<-1;
        }



    return 0;
}
