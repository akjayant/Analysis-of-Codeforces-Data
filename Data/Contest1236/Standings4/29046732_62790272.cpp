//≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈
//  Date : Plz press Shift + Ctrl + . in proper Sublime
//  Author : Sakii
//  website : zcqiever.tk
//  I'm so vegetable , QAQ..
//≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈

#include<bits/stdc++.h>
#define re register
#define il inline
#define lowbit(x) x&(-x)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <class T> inline void read(T &s){
    s = 0; re char ch = getchar(); re int w = 0;
    while(!isdigit(ch)) w |= ch == '-', ch = getchar();
    while(isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    if(w) s = -s;
}

namespace Sakii {

    il void main() {
        int t;
        read(t);
        while(t--) {
            int a,b,c;
            int ans = 0;
            read(a); read(b); read(c);
            if(b==0) {printf("0\n"); continue;}
            ans = ans + min(b*3,c/2*2+c/2*2/2);
            b -= min(b,c/2*2/2);
            //printf("%d\n", b);
            if(b>=2) {
                ans = ans + min(a*3,b/2*2+b/2*2/2);
            }
            printf("%d\n", ans);
        }
        return;
    }
}

int main(){
    Sakii::main();
    return 0;
}

