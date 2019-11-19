#include<bits/stdc++.h>

using namespace std;

#define Q int t, q; scanf("%d", &t); for(q=1; q<=t; q++)
#define lli long long int

int zero[1000000];

int main()
{
    lli n;
    cin >> n;
    lli nn = n;
    for(lli i=2; i*i<=n; i++){
        if(n%i == 0){
            while(nn%i==0){
                nn /= i;
            }
            if(nn == 1){
                cout << i << "\n";

            }
            else{
                cout << "1\n";

            }
            return 0;
        }
    }
    cout << n << "\n";

    return 0;
}
