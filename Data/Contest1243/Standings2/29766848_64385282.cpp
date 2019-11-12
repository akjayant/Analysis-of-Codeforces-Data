#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define debug2(a, b) cerr<<#a<<"="<<(a)<<" ";debug(b)
#define debug3(a, b, c) cerr<<#a<<"="<<(a)<<" ";debug2(b, c)
#define debug4(a, b, c, d) cerr<<#a<<"="<<(a)<<" ";debug3(b, c, d)
#define debug5(a, b, c, d, e) cerr<<#a<<"="<<(a)<<" ";debug4(b, c, d, e)
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
void printArray(const T * a, int n, ostream& out = cerr);
template<class T>
void printArray(const vector<T> &arr, ostream& out = cerr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
char a[10003];
char b[10003];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%s", a);
        scanf("%s", b);
        vector<pii> ans;
        bool possible = true;
        for(int i=0;i<n;++i){
            if(a[i] != b[i]){
                bool found = false;
                for(int j=i+1;j<n;++j){
                    if(a[j] == a[i]){
                        swap(a[j], b[i]);
                        ans.pb({j, i});
                        found = true;
                        break;
                    }
                }
                if(!found){
                    for(int j=i+1;j<n;++j){
                        if(b[j] == a[i]){
                            ans.pb({i+1, j});
                            ans.pb({i+1, i});
                            swap(a[i+1], b[j]);
                            swap(a[i+1], b[i]);
                            found = true;
                            break;
                        }
                    }
                }
                if(!found){
                    possible = false;
                    break;
                }
            }
        }
        // printf("%s\n", a);
        // printf("%s\n", b);
        if(ans.size() > 2*n) possible = false;
        puts(possible ? "Yes" : "No");
        if(possible){
            if(ans.size() == 0){
                puts("1\n1 1\n");
            }
            else {
                printf("%d\n", (int)ans.size());
                for(const pii & x : ans){
                    printf("%d %d\n", x.fi+1, x.se+1);
                }
            }
        }
    }
    return 0;
}

/* Template Function */
template<class T>
void printArray(const T * a, int n, ostream& out){
    for(int i=0;i<n;++i){
        out<<a[i]<<" ";
    }
    out<<endl;
}

template<class T>
void printArray(const vector<T> &arr, ostream& out){
    for(const T& x : arr){
        out<<x<<" ";
    }
    out<<endl;
}