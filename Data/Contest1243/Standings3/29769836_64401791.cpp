#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
int Gcd(int a,int b){if (b == 0) return a; return Gcd(b , a%b);}
int Lcm(int a, int b){ return a/Gcd(a,b)*b;}
template <class T>
void read(T &x) {
    static char ch;
    static bool neg;
    for(ch = neg = 0; ch < '0' || '9' < ch; neg |= ch == '-', ch = getchar());
    for(x = 0; '0' <= ch && ch <= '9'; (x *= 10) += ch - '0', ch = getchar());
    x = neg ? -x : x;
}
const int maxn = 1e6 + 10;
char s[maxn],t[maxn];
int cnt1[100],cnt2[100];
vector<pair<int,int> > ans;
int main(){
    int T;
    read(T);
    while(T--){
        ans.clear();
        for(int i=0; i<30; i++) cnt1[i] = cnt2[i] = 0;
        int n;
        read(n);
        scanf("%s%s",s,t);
        for(int i=0; i<n; i++){
            cnt1[s[i] - 'a']++;
            cnt2[t[i] - 'a']++;
        }
        int res = 0;
        for(int i=0; i<26; i++){
            if ( (cnt1[i] + cnt2[i]) & 1 ) res = 1;
        }
        if (res){
            puts("No");
            continue;
        }
        for(int i=0; i<n; i++){
            if (s[i] != t[i]){
                if (i == n){
                    res = 1;
                    break;
                }
                int tag = 0;
                for(int j=i+1; j<n; j++){
                    if (t[i] == t[j]){
                        swap(s[i],t[j]);
                        ans.push_back(make_pair(i+1,j+1));
                        tag = 1;
                        break;
                    }
                }
                if (tag == 0){
                    for(int j=i+1; j<n; j++){
                        if (s[j] == t[i]){
                            swap(t[i+1],s[j]);
                            swap(t[i+1],s[i]);
                            ans.push_back(make_pair(j+1,i+2));
                            ans.push_back(make_pair(i+1,i+2));
                            tag = 1;
                            break;
                        }
                    }
                }
                if (!tag) {
                    res = 1;
                    break;
                }
            }
        }
        if (res) puts("No");
        else{
            puts("Yes");
            printf("%d\n",(int)ans.size());
            for(auto p : ans){
                printf("%d %d\n",p.first,p.second);
            }
        }
    }
    return 0;
}