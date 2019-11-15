#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;
typedef long long int ll;
typedef pair<int,int> pi;
typedef unsigned long long int ull;

ll lsone(ll p){return(p & -p);}

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main(){
    std::ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a, b, n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        if (gcd(a, b) == 1){
            cout << "Finite" << endl;
        }
        else{
            cout << "Infinite" << endl;
        }
    }
}
