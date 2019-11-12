#include <bits/stdc++.h>

#define ll long long
#define llu unsigned long long
#define rep(i, n) for(i = 0; i < n; i++)
#define rep1(i, n) for(i = 1; i <= n; i++)
#define rev(i, n) for(i = n-1; i >= 0; i--)
#define rev1(i, n) for(i = n; i > 0; i--)
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define pf push_front
#define mk make_pair
#define line cout<<endl;
#define dbug(n) cout<<#n<<" "<<n<<"|| ";
#define dbug2(n, m) cout<<#n<<" "<<n<<" "<<#m<<" "<<m<<" "<<endl;
#define dbug3(n, m, l) cout<<#n<<" "<<n<<" "<<#m<<" "<<m<<" "<<#l<<" "<<l<<" "<<endl;
#define dbug4(n, m, l, o) cout<<#n<<" "<<n<<" "<<#m<<" "<<m<<" "<<#l<<" "<<l<<" "<<#o<<" "<<o<<" "<<endl;
#define dbug5(n, m, l, o, p) cout<<#n<<" "<<n<<" "<<#m<<" "<<m<<" "<<#l<<" "<<l<<" "<<#o<<" "<<o<<" "<<#p<<" "<<p<<" "<<endl;
#define show_ara(ara, n) for(int iii  = 0; iii < n; iii++) cout<<ara[iii]<<" "; line
#define show_araln(ara, n) for(int iii  = 0; iii < n; iii++) cout<<ara[iii]<<endl;

#define vowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define vowelC(a) (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
#define odd(a) ((a % 2) == 1)
#define even(a) ((a % 2) == 0)
#define iflower(c) (c >= 'a' && c <= 'z')
#define ifupper(c) (c >= 'A' && c <= 'Z')
#define ifnum(c) (c >= '0' && c <= '9')
#define ifAlpha_numaric(c) (iflower(c) || ifupper(c) || ifnum(c))
//#define stll vector<int>v; string s, s1, s2, anss, rlts; unordered_map<ll, ll>ump; map<ll, ll>mp; unordered_set<ll>ust; set<ll>st; stack<ll>S; queue<ll>Q; deque<ll>dq; priority_queue<ll>pq; vector<pair<ll, ll> >pr;

#define binary_representation(n) for(int i = 1<<30, J = 1; i > 0; i >>= 1, J++){ if(!(J%4)) cout<<" "; (n&i)? cout<<"1": cout<<"0";} line;
#define swapx(A, B) A = A^B; B = A^B; A = A^B;

using namespace std;

const int N = 3e5+100;
const int NN = 550;
const int MM = 550;
const ll mod = 9e10+7;
const double ESP = 1e-9;

vector<ll>v, v1, v2, vara[N]; vector<pair<ll, ll> >pr;
string s, ss, s1, s2, s3, anss, rlts;
map<char, ll>mp; unordered_map<ll, ll>ump;
set<ll>st; unordered_set<ll>ust;
stack<ll>S; queue<ll>Q; deque<ll>dq; priority_queue<ll>pq;

struct stk{
    ll a, pos;
};

ll a, b, c, d,   t, tc,   n, m,   i, j, k, l,   f,   x, y, z, tmp;
ll ans, cnt, cnt1, cnt2, rlt;
ll mn = numeric_limits<long long>::max(), mx = numeric_limits<long long>::min(), mnn = INT_MAX, mxx = INT_MIN;
ll ara[N], ara1[N], arr[NN][MM];
bool ff[N] = {false};
stk stk[N];
ll gcd(ll a, ll b){ return abs(__gcd(a, b));}
ll lcm(ll a, ll b){ return abs(a*b)/gcd(a, b);}
void stl_clear(){ v.clear();v1.clear();v2.clear();pr.clear();mp.clear();st.clear();ump.clear();ust.clear(); dq.clear();for(int i = 0; i < n; i++) vara[i].clear();while(!Q.empty()){Q.pop();}while(!S.empty()){S.pop();}while(!pq.empty()){pq.pop();}s="";ss="";s1="";s2="";s3="";anss="";rlts="";}
void all_clear(){ a=b=c=d=t=tc=n=m=i=j=k=l=f=x=y=z=tmp=ans=cnt=cnt1=cnt2=rlt=0; mn = numeric_limits<long long>::max(), mx = numeric_limits<long long>::min(), mnn = INT_MAX, mxx = INT_MIN; memset(ara, 0, sizeof(ara)); memset(ara1, 0, sizeof(ara1)); memset(arr, 0, sizeof(arr[0][0]*NN*MM)); memset(ff, 0, sizeof(ff)); stk[N] = {}; stl_clear();}
int main()
{
    fastread

    cin>>t;

    while(t--){
        cin>>n;
        cin>>s1>>s2;
        mp.clear();
        pr.clear();
        rep(i, n){
            mp[s1[i]]++;
            mp[s2[i]]++;
        }

        for(auto a: mp){
            if(odd(a.second)){
                cout<<"NO"<<endl;
                goto f1;
            }
        }
        rep(i, n){
            if(s1[i] != s2[i]){
                for(j = i+1; j < n; j++){
                    if(s1[i] == s1[j]){
                        pr.pb({j, i});
                        a = s2[i];
                        s2[i] = s1[j];
                        s1[j] = a;
                        break;
                    }
                    if(s2[i] == s2[j]){
                        pr.pb({i, j});
                        a = s1[i];
                        s1[i] = s2[j];
                        s2[j] = a;
                        break;
                    }
                    if(s1[i] == s2[j]){
                        pr.pb({j, j});
                        pr.pb({j, i});

                        swap(s2[i], s2[j]);
                        a = s1[j];
                        s1[j] = s2[j];
                        s2[j] = a;

                        break;
                    }
                    if(s2[i] == s1[j]){
                        pr.pb({j, j});
                        pr.pb({i, j});

                        swap(s1[i], s1[j]);
                        a = s1[j];
                        s1[j] = s2[j];
                        s2[j] = a;

                        break;
                    }

                }
            }
        }
//        dbug(pr.size());cout<<endl;
        if(pr.size() <= 2*n){
            cout<<"Yes"<<endl;
            cout<<pr.size()<<endl;

            for(auto a: pr){
                cout<<a.first+1<<" "<<a.second+1<<endl;
            }
        }
        else{
            cout<<"No"<<endl;
        }
        f1:
            continue;
    }

    rett:
    return 0;
    all_clear();
    return main();
}

