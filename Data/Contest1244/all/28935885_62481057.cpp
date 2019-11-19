/**
 *　　　　　　　　┏┓　　 　┏┓
 * 　　　　　　　┏┛┗━━━━━━━┛┗━━━┓
 * 　　　　　　　┃　　　　　　　┃ 　
 * 　　　　　　　┃　　　━　　 　┃
 * 　　　　　　　┃　＞　　　＜　┃
 * 　　　　　　　┃　　　　　　　┃
 * 　　　　　　　┃...　⌒　... 　┃
 * 　　　　　　　┃　　　　　　　┃
 * 　　　　　　　┗━┓　　　┏━┛
 * 　　　　　　　　　┃　　　┃　Code is far away from bug with the animal protecting　　　　　　　　　　
 * 　　　　　　　　　┃　　　┃   神兽保佑,代码无bug
 * 　　　　　　　　　┃　　　┃　　　　　　　　　　　
 * 　　　　　　　　　┃　　　┃  　　　　　　
 * 　　　　　　　　　┃　　　┃
 * 　　　　　　　　　┃　　　┃　　　　　　　　　　　
 * 　　　　　　　　　┃　　　┗━━━┓
 * 　　　　　　　　　┃　　　　　　　┣┓
 * 　　　　　　　　　┃　　　　　　　┏┛
 * 　　　　　　　　　┗┓┓┏━┳┓┏┛
 * 　　　　　　　　　　┃┫┫　┃┫┫
 * 　　　　　　　　　　┗┻┛　┗┻┛
 */
// warm heart, wagging tail,and a smile just for you!
//
//                            _ooOoo_
//                           o8888888o
//                           88" . "88
//                           (| -_- |)
//                           O\  =  /O
//                        ____/`---'\____
//                      .'  \|     |//  `.
//                     /  \|||  :  |||//  \
//                    /  _||||| -:- |||||-  \
//                    |   | \  -  /// |   |
//                    | \_|  ''\---/''  |   |
//                    \  .-\__  `-`  ___/-. /
//                  ___`. .'  /--.--\  `. . __
//               ."" '<  `.___\_<|>_/___.'  >'"".
//              | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//              \  \ `-.   \_ __\ /__ _/   .-` /  /
//         ======`-.____`-.___\_____/___.-`____.-'======
//                            `=---='
//        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//                     佛祖保佑      永无BUG
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long uLL;
#define ls rt<<1
#define rs rt<<1|1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define bug printf("*********\n")
#define FIN freopen("input.txt","r",stdin);
#define FON freopen("output.txt","w+",stdout);
#define IO ios::sync_with_stdio(false),cin.tie(0)
#define debug1(x) cout<<"["<<#x<<" "<<(x)<<"]\n"
#define debug2(x,y) cout<<"["<<#x<<" "<<(x)<<" "<<#y<<" "<<(y)<<"]\n"
#define debug3(x,y,z) cout<<"["<<#x<<" "<<(x)<<" "<<#y<<" "<<(y)<<" "<<#z<<" "<<z<<"]\n"
const int maxn = 3e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double Pi = acos(-1);
LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}
LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}
double dpow(double a, LL b) {
    double ans = 1.0;
    while(b) {
        if(b % 2)ans = ans * a;
        a = a * a;
        b /= 2;
    } return ans;
}
LL quick_pow(LL x, LL y) {
    LL ans = 1;
    while(y) {
        if(y & 1) {
            ans = ans * x % mod;
        } x = x * x % mod;
        y >>= 1;
    } return ans;
}
char str[maxn];

int main() {
#ifndef ONLINE_JUDGE
    FIN
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d %s", &n, str + 1);
        int Maxpos = 0;
        int Minpos = INF;
        int flag = 1;
        for(int i = 1; i <= n; i++) {
            if(str[i] == '1') {
                Maxpos = max(Maxpos, i);
                Minpos = min(Minpos, i);
                flag = 0;
            }
        }
        if(flag) {
            printf("%d\n", n);
        } else {
            int ans = max(Maxpos * 2, (n - Minpos + 1) * 2);
            printf("%d\n", ans);
        }
    }
    return 0;
}
