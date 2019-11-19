typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        ll n;
        std::cin >> n;
        ll pg = 0;//偶数
        for (int j = 0; j < n; j++) {
            ll tmp;
            std::cin >> tmp;
            if(tmp %2==0){
                pg++;
            }
        }
        ll m;
        std::cin >> m;
        ll qg = 0;
        for (int j = 0; j < m; j++) {
            ll tmp;
            std::cin >> tmp;
            if(tmp%2==0){
                qg++;
            }
        }
        std::cout << pg*qg+(n-pg)*(m-qg) << std::endl;
    }
}
