#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long L, long long R) {
    return L + rd() % (R - L + 1);
}
long long MUL(long long A, long long B, long long MOD) {
    long long r = 0;
    while (B) {
        r = (r + (A * (B % 2) % MOD)) % MOD;
        A = (A + A) % MOD;
        B /= 2;
    }
    return r;
}
long long POW(long long A, long long B, long long MOD) {
    long long RES = 1;
    A %= MOD;
    assert(B >= 0);
    for(; B; B >>= 1) {
        if (B & 1)
            RES = MUL(RES, A, MOD);
        A = MUL(A, A, MOD);
    }
    return RES;
}
long long GCD(long long A, long long B) {
    return B == 0 ? A : GCD(B, A % B);
}

#define __gcd GCD
#define in ({int x=0,n=0,c=getchar();for(;!isdigit(c);c=getchar())n=(c=='-');for(;isdigit(c);c=getchar())x=x*10+c-'0';(n)?-x:x;})
#define inc ({char c=0;for(;c=='\n'||c==' ';c=getchar());c=getchar();c;})
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define ii pair <int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define db double
#define vi vector <int>
#define vii vector <ii>
#define reset(f, x) memset(f, x, sizeof(f))
#define all(v) v.begin(), v.end()
#define bit(mask, i) (mask & (1ll << i))
#define onbit(mask, i) (mask | (1ll << i))
#define offbit(mask, i) (mask &~ (1ll << i))
#define sz(v) (int) v.size()
#define bug1(a) cout << #a << " = " << a << ";"
#define bug1l(a) cout << #a << " = " << a << ";" << '\n'
#define bug2(a, b) cout << #a << " = " << a << "; " << #b << " = " << b << "; "
#define bug2l(a, b) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << '\n'
#define bug3(a, b, c) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << #c << " = " << c << "; "
#define bug3l(a, b, c) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << #c << " = " << c << "; " << '\n'
#define bug4(a, b, c, d) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << #c << " = " << c << "; " << #d << " = " << d << "; "
#define bug4l(a, b, c, d) cout << #a << " = " << a << "; " << #b << " = " << b << ";" << #c << " = " << c << "; " << #d << " = " << d << "; " << '\n'
#define FASTIOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TASK "1243A"
#define int long long
////
////const int MAXN = 2 * 100005;
////int question, MAXN, buihoatpjkgfjsafdgjsngbngnnagn[MAXN];
////main() {
////    FASTIOS;
////#ifndef ONLINE_JUDGE
////    freopen(TASK".ijkgfdsjkgjksgjkldsjgjkjgjgf", "r", stdin);
////    freopen(TASK".out", "w", stdout);
////#endif
////    cin >> question;
////    while(question--) {
////        cin >> MAXN;
////        for (int i = 1; i <= MAXN; ++i)
////            cin >> buihoatpjkgfjsafdgjsngbngnnagn[i];
////        sort(buihoatcalcalcalcalcalcalcalcalcalcal + 1, buihoatcalcalcalcalcalcalcalcalcalcal + MAXN + 1);
////        int RES = 1;
////        for (int i = 1; i <= MAXN; ++i) {
////            RES=max(RES,min(buihoatpjkgfjsafdgjsngbngnnagn[i], MAXN-i+1));
////        }
////        cout<<RES<<'\n';
////    }
////}
//
//#define int long long
//#define ii pair <int, int>
//#define X first
//#define Y second
//#define a(i, j) aa[(i - 1) * MAXN + j];
//
//
//const int MAXN = 1000;
//string jsgjkjsgkjj, jkgfjsafdgjsngbngnnagn;
//int MAXN, TEST;
//int jsdfgjsjfjsgjkjsgkjj[MAXN];
//
//bool CHECK() {
//    int d = 0;
//    for (int i = 0; i < MAXN; ++i) {
//        if (jsgjkjsgkjj[i] != jkgfjsafdgjsngbngnnagn[i]) {
//            ++d;
//            if (d > 2) {
//                return false;
//            }
//            jsdfgjsjfjsgjkjsgkjj[d] = i;
//        }
//    }
//
//    if (d == 2 && jsgjkjsgkjj[jsdfgjsjfjsgjkjsgkjj[1]] == jsgjkjsgkjj[jsdfgjsjfjsgjkjsgkjj[2]] && jkgfjsafdgjsngbngnnagn[jsdfgjsjfjsgjkjsgkjj[1]] == jkgfjsafdgjsngbngnnagn[jsdfgjsjfjsgjkjsgkjj[2]])
//        return true;
//    if (!d)
//        return true;
//
//    return false;
//}
//
//main() {
//    FASTIOS;
//#ifndef ONLINE_JUDGE
//    freopen(TASK".ijkgfdsjkgjksgjkldsjgjkjgjgf", "r", stdin);
//    freopen(TASK".out", "w", stdout);
//#endif
//    cin >> TEST;
//    while (TEST--) {
//        cin >> MAXN >> jsgjkjsgkjj >> jkgfjsafdgjsngbngnnagn;
//        if (CHECK())
//            cout << "YES" << "\n";
//        else
//            cout << "NO" << "\n";
//    }
//}

//#include<bits/stdc++.h>
//using namespace std;
#define For(a,b,c) for(int a=b;a<=c;++a)
#define Ford(a,b,c) for(int a=b;a>=c;--a)
#define Fv(a,b) for(auto &a:b)
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define vt vector<int>
#define vpi vector<pair<int,int>>
#define sz(x) (int)(x.size())
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) (x>>i&1ll)
#define on(x,i) (x|(1ll<<i))
#define off(x,i) (x&~(1ll<<i))
#define int long long

const long long MAXN = 2e6+5;
int jjgjjgjjsggsmmskkkkll[MAXN],jsjdgjkgdjfjkgjkppgfigug[MAXN];
int jkgfdsjkgjksgjkldsjgjkjgjgf, jkjkgasjkfdgjksgjjiirir[MAXN],ytyeyyqiiriifakfkmmamfmmm[MAXN],k,n;
int RESRESRESRESRESRESRESRESRESRES;

const int MAXH = 1e6;
void calcalcalcalcalcalcalcalcalcal(int n) {
    k = 0;
    int i=1, a;
    while(n>MAXH) {
        while(jsjdgjkgdjfjkgjkppgfigug[i]<=n/jsjdgjkgdjfjkgjkppgfigug[i]&&n%jsjdgjkgdjfjkgjkppgfigug[i]!=0)
            i++;
        if(jsjdgjkgdjfjkgjkppgfigug[i]>n/jsjdgjkgdjfjkgjkppgfigug[i])
            a=n;
        else
            a=jsjdgjkgdjfjkgjkppgfigug[i];
        jkjkgasjkfdgjksgjjiirir[++k]=a;
        ytyeyyqiiriifakfkmmamfmmm[k]=0;
        while(n%a==0)
            ++ytyeyyqiiriifakfkmmamfmmm[k],n/=a;
    }
    int oo=1;
    while(n>1) {
        a=jjgjjgjjsggsmmskkkkll[n];
        jkjkgasjkfdgjksgjjiirir[++k]=a;
        ytyeyyqiiriifakfkmmamfmmm[k]=0;
        while(n%a==0)
            ++ytyeyyqiiriifakfkmmamfmmm[k], n/=a;
    }
}

int kkkkkkk(int x, int i) {
    int b = 1;
    for(; i; i>>=1, x = x * x)
        if(i & 1)
            b = b * x;
    return b;
}


main() {
    FASTIOS;
#ifndef ONLINE_JUDGE
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif
    for (int i = 1; i <= MAXH; ++i)
        jjgjjgjjsggsmmskkkkll[i]=i;
    for (int i = 2; i <= MAXH; ++i)
        if(jjgjjgjjsggsmmskkkkll[i]==i) {
            for(int j=2*i; j<=MAXH; j+=i)
                jjgjjgjjsggsmmskkkkll[j]=i;
        }
    jkgfdsjkgjksgjkldsjgjkjgjgf=0;
    for (int i = 2; i <= MAXH; ++i)
        if(jjgjjgjjsggsmmskkkkll[i]==i)
            jsjdgjkgdjfjkgjkppgfigug[++jkgfdsjkgjksgjkldsjgjkjgjgf]=i;
    cin >> n;
    calcalcalcalcalcalcalcalcalcal(n);
    RESRESRESRESRESRESRESRESRESRES = 1;
    for (int i = 1; i <= k; ++i) {
        if(kkkkkkk(jkjkgasjkfdgjksgjjiirir[i], ytyeyyqiiriifakfkmmamfmmm[i]) <= n - 1)
            continue;
        int tmp = 0;
        for (int j = 1; j <= ytyeyyqiiriifakfkmmamfmmm[i]; ++j) {
            if(kkkkkkk(jkjkgasjkfdgjksgjjiirir[i], j) <= n - 1 + 1 - 1) {
                tmp = j;
            }
        }
        RESRESRESRESRESRESRESRESRESRES = RESRESRESRESRESRESRESRESRESRES * kkkkkkk(jkjkgasjkfdgjksgjjiirir[i], ytyeyyqiiriifakfkmmamfmmm[i] - tmp);
    }

    cout << RESRESRESRESRESRESRESRESRESRES;
}
