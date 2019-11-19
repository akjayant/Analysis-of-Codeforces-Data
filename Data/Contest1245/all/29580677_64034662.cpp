///+----------------------------------------+\\\
///|   ___  __  __  ____  ____  ____  _  _  |\\\
///|  / __)(  )(  )(_  _)( ___)(_  _)( \( ) |\\\
///| ( (__  )(__)(   )(   )__)   )(   )  (  |\\\
///|  \___)(______) (__) (____) (__) (_)\_) |\\\
///|                                        |\\\
///+-----------------------QUẢN-TIẾN-NGHĨA--+\\\

/// CODEFORCES TEMPLATE - version 1.0.3
/// © 2019 Quản Tiến Nghĩa (a.k.a CuteTN)

/// Hạnh đáng iu
/// Hạnh dễ thưn

#include <bits/stdc++.h>
using namespace std;

/// OPTIMIZE SOMETHING I DONT EVEN UNDERSTAND
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/// USEFUL MACROS
#define endl '\n'
#define Fi first
#define Se second
#define Pb push_back
#define Mp make_pair
#define is ==
#define isnt !=
#define momo % MODULO
#define fd / (float)

#define szOf(container_) ((ll)container_.size())
#define allV(container_) container_.begin(),container_.end()
#define sortV(container_) sort(container_.begin(),container_.end())
#define elif else if

#define loopTestCases int numberOfCases; read(numberOfCases); while(numberOfCases--)
#define forEach(element_, container_) for(auto&element_: container_)
    // forEach can not be used for static array
#define forUp(iterator_, rangeL_, rangeR_) for(auto iterator_ = rangeL_; iterator_ <= rangeR_; iterator_++)
#define forDown(iterator_, rangeR_, rangeL_) for(auto iterator_ = rangeR_; iterator_ >= rangeL_; iterator_--)
#define forTimes(times_) for(ll iterator_ = 1; iterator_ <= times_; iterator_++)

#define readNew(varName, type) type varName; read(varName)

#define rnll5(a, b, c, d, e) readNew(a,ll); rnll4(b, c, d, e)
#define rnll4(a, b, c, d)    readNew(a,ll); rnll3(b, c, d)
#define rnll3(a, b, c)       readNew(a,ll); rnll2(b, c)
#define rnll2(a, b)          readNew(a,ll); rnll1(b)
#define rnll1(a)             readNew(a,ll)
    // read New long long: readNew(.,ll) is frequently used

#define debug(varName)       clearedAllDebug = false; cerr<<"DEBUG: "<<#varName << " = " << varName << "\n";
    // debug variables
#define debugV(vectorName)   clearedAllDebug = false; cerr<<"DEBUG: "<<#vectorName<<" = {"; for(auto&element:vectorName) cerr<<" "<<element<<" "; cerr<<"}\n";
    // debug vectors
#define debugN(noteString)   clearedAllDebug = false; cerr<<"DEBUG: "<<noteString<<"\n";
    // debug notes

/// FREQUENTLY USED TYPES
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

/// FREQUENTLY USED CONSTS
const ll MODULO = ll(1e9 + 7);
const ll oo = (ll)1e18;
const double eps = 1e-6;
const double pi = (atan(1)*4);
const char* YES_ANS = "YES";
const char* NO_ANS  = "NO";
const bool HanhIsSoCute = true;
bool clearedAllDebug = true;

/// FREQUENTLY USED FUNCTIONS
ll myPow(ll x, ll y, ll m = MODULO)
/** (x^y)%m */
{
    ll ans=1;
    ll t = x;
    while(y)
    {
        if(y&1)
            (ans*=t) %= m;
        (t*=t) %= m;
        y>>=1;
    }
    return ans;
}

bool isInc()                     { return true; }
bool isInc(auto val1)            { return true; }
bool isInc(auto val1, auto val2) { return val1 <= val2; }
template<typename Type, typename... Args>
bool isInc(Type val1, Type val2, Args... args)
{
    bool temp = isInc(val2, args...);
    return (val1 <= val2) && temp;
}

auto mmax(auto x)              { return x;                     }
auto mmax(auto x, auto y)      { return max(x,y);              }
auto mmax(auto x, auto... args){ return max(x, mmax(args...)); }

auto mmin(auto x)              { return x;                     }
auto mmin(auto x, auto y)      { return min(x,y);              }
auto mmin(auto x, auto... args){ return min(x, mmin(args...)); }

ll sgn(auto a)
/** get the sign of a number a */
{
    if(a == 0)
        return 0;
    return (a<0? -1:1);
}

void varMod(ll & x, bool negativeAllow = false)
{
    x %= MODULO;
    if (! negativeAllow)
        x = (x + MODULO) % MODULO;
}
void varMod(int& x, bool negativeAllow = false)
{
    const int iMODULO = (int)MODULO;
    x %= iMODULO;
    if (! negativeAllow)
        x = (x + iMODULO) % iMODULO;
}


bool isf(auto a, auto b)
/** is Equal for floating point number */
{
    return (double)abs(a - b) <= eps;
}

/// FAST IO
const char* ELEMENT_SEPARATOR = " ";
const int POSITION_AFTER_DECIMAL = 6;
void print()             {}
void print(int a)        { printf("%d"  , a); }
void print(long long a)  { printf("%lld", a); }
void print(char a)       { printf("%c"  , a); }
void print(char*a)       { printf("%s"  , a); }
void print(const char*a) { printf("%s"  , a); }
void print(string a)     { printf("%s"  , a.c_str()); }
void print(bool a)       { printf( a? YES_ANS:NO_ANS ); }
void print(float a)      { string format = "%." + to_string(POSITION_AFTER_DECIMAL) + "f"; printf(format.c_str() , a); }
void print(double a)     { string format = "%." + to_string(POSITION_AFTER_DECIMAL) + "f"; printf(format.c_str() , a); }
void print(pair<auto,auto> a)
{
    print(a.Fi);
    print(ELEMENT_SEPARATOR);
    print(a.Se);
}
void print(vector<auto> a)
{
    forEach(element,a)
    {
        print(element);
        print(ELEMENT_SEPARATOR);
    }
}

void print(char a, auto... args)
{
    print(a);
    if(a != endl)
        print(ELEMENT_SEPARATOR);
    print(args...);
}
template<typename Type, typename... Args>
void print(Type a, Args... args)
{
    print(a);
    print(ELEMENT_SEPARATOR);
    print(args...);
}

const set<char> ENDSTRING_CHARACTER = {'\n', ' '};
void read(int&a)        { scanf("%d"   , &a); }
void read(long long&a)  { scanf("%lld" , &a); }
void read(float&a)      { scanf("%f"   , &a); }
void read(double&a)     { scanf("%lf"  , &a); }
void read(char&a)       { scanf("%c"   , &a); }
void readc(char&a)
/** ignore all unneccesary characters */
{
    char tempChar;
    do
    {
        scanf("%c", &tempChar);
    }
    while(ENDSTRING_CHARACTER.count(tempChar) != 0);
    a = tempChar;
}
void read(string&a)
{
    string res = "";
    char tempChar;
    while (true)
    {
        scanf("%c", &tempChar);
        if(ENDSTRING_CHARACTER.count(tempChar) != 0)
        {
            if(res.size() != 0)
                break;
        }
        else
            res = res + tempChar;
    }
    a = res;
}
void read(pair<auto,auto>&a)
{
    read(a.Fi);
    read(a.Se);
}
void read(vector<auto>&a)
{
    forEach(element, a)
        read(element);
}

template<typename Type, typename... Args>
void read(Type&a, Args&... args)
{
    read(a);
    read(args...);
}

void readVector(vector<auto>&vectorName, ll vectorSize)
{
    vectorName.resize(vectorSize);
    read(vectorName);
}
void readVector(vector<auto>&vectorName, ll startPos, ll endPos)
{
    vectorName.resize(endPos+1);
    forUp(i, startPos, endPos)
        read(vectorName[i]);
}


/// START & END
void onStartMain()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void onEndMain()
{
    if(! clearedAllDebug)
    {
        printf("\n");
        printf("+-------------------------------------+\n");
        printf("| WARNING: NOT REMOVED DEBUG MESSAGES |\n");
        printf("+-------------------------------------+");
        exit(10101010);
    }
    exit(0);
}


///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\
/// ALGORITHM TEMPLATE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\


///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\
/// SOLUTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\

const ll MAXSIZE = 2000 + 10;

ll n;
pll pos[MAXSIZE];
ll c[MAXSIZE][MAXSIZE];
ll d[MAXSIZE];
ll k[MAXSIZE];
bool locked[MAXSIZE];
ll trace[MAXSIZE];
pll l[MAXSIZE];

ll cnt0 = 0;

ll mahdis(pll a, pll b)
{
    return abs(a.Fi-b.Fi) + abs(a.Se - b.Se);
}

ll prim()
{
    forUp(i,0,MAXSIZE-1)
    {
        locked[i] = false;
        d[i]= oo;
    }
    d[0] = 0;
    ll cnt = 0;
    ll sum = 0;

    forUp(i,0,n)
    {
        ll u = -1;
        forUp(i,0,n)
        {
            if(! locked[i])
                if( (u ==-1) || (d[u] > d[i]) )
                {
                    u = i;
                }
        }

        locked[u] = true;
        l[cnt] = {trace[u], u};
        if(trace[u] == 0)
        {
            cnt0++;
        }
        cnt++;
        sum+=d[u];

        forUp(i,0,n)
        {
            if(! locked[i])
                if( c[u][i] < d[i] )
                {
                    d[i] = c[u][i];
                    trace[i] = u;
                }
        }
    }

    sort(l, l+n+1);
    return sum;
}

int main()
{
    onStartMain();

    read(n);
    forUp(i,1,n)
    {
        read(pos[i].Fi, pos[i].Se);
    }
    forUp(i,1,n)
    {
        read(c[0][i]);
        c[i][0] = c[0][i];
    }
    forUp(i,1,n)
    {
        read(k[i]);
    }
    forUp(i,1,n)
    {
        forUp(j,1,n)
        {
            c[i][j] = (k[i] + k[j])*mahdis(pos[i], pos[j]);
        }
    }

    print(prim(), endl);
    print(cnt0-1,endl);

    forUp(i,1,cnt0-1)
    {
        print(l[i].Se, ' ');
    }

    print(endl);
    print(n - cnt0 + 1,endl);
    forUp(i,cnt0,n)
    {
        print(l[i].Fi,l[i].Se,endl);
    }

    onEndMain();
}

/// Hạnh đáng iu
/// Hạnh dễ thưn


///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\
/// TEST CASES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\

/* Test case 1
input

output
*/
