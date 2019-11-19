#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long int uLL;
typedef unsigned int uint;

const int N = 100007;
LL tab[N];
int n;
LL k;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> tab[i];
    }
    sort(tab+1, tab+n+1);
    LL l = 1;
    LL p = n;
    LL minim = tab[1];
    LL maks = tab[n];
    while(k > 0 && l < p){
        if(l < n-p+1){
            if((tab[l+1]-tab[l])*l <= k){
                k-= (tab[l+1]-tab[l])*l;
                minim = tab[l+1];
                while(tab[l+1] == minim){
                    l++;
                }
                continue;
            }
            else{
                LL ile = k/l;
                minim += ile;
                break;
            }
        }
        else{
            if((tab[p]-tab[p-1])*(n-p+1) <= k){
                k -= (tab[p]-tab[p-1])*(n-p+1);
                maks = tab[p-1];
                while(tab[p-1] == maks){
                    p--;
                }
                continue;
            }
            else{
                LL ile = k/(n-p+1);
                maks -= ile;
                break;
            }
        }
    }
    cout << maks-minim << '\n';
    return 0;
}
