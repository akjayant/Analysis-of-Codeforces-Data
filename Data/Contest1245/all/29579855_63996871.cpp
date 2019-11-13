//careful references in recursion
//careful long long int and mod always OMG
//careful return types of std such as int(ceil)
//io manip lookup for decimal control
//WATCH OUT GOING OVER MAX thru operations spam mod
// vectors overflow arrays do NOT
//lower bound is first greater or equal
//uper is first greater
// if TLE play around with compiler
// use static is helpful!!
//take note of test stuff that need to be changed before submission
// careful when u use garbage from abroad
// modeling stuff as num going below 0 above n
// number theory infinite due to multple of each other
//careful not finding stuff in dictionaries
//stupid cout precision and sci notations
// set rbegin() or --end() for last
//careful multiset removal just use  heapp
#include<bits/stdc++.h>
using namespace std;

//macros and shortcuts
#define loop(i, n) for(int i = 0; i < n; i++)
#define pool(i, n) for(int i = n-1; i >=0; i--)
#define loopy(i, o, n) for(int i = o; i < n; i++)
#define pooly(i, o, n) for(int i = o-1; i >= n; i--)

#define scan(it, d) for(auto it=d.begin(); it!=d.end(); it++)

typedef long long ll; //can be modified to long/int in emergencies.
typedef long long lll;

const int maxint=2147483646;
const int minint=-2147483646;
const lll maxlll=9223372036854775805;
const lll minlll=-9223372036854775805;
const ll mody=1000000007;

// here lie the output functions
template<class T>
ostream& operator<<(ostream& os, vector<T>& v){
    os<<"[";
    for(int i=0; i<v.size(); i++){
        os<<v[i];
        if(i!=v.size()-1){
            os<<", ";
        }
    }
    os<<"]";
    //cout<<endl;
    return os;
}
template<class T, class U>
ostream& operator<<(ostream& os, unordered_map<T,U>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<i->first<<": "<<i->second;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    //os<<endl;
    return os;
}
template<class T, class U>
ostream& operator<<(ostream& os, pair<T,U>& dt){
    os<<"<"<<dt.first<<","<<dt.second<<">";
    return os;
}
template <typename T, unsigned int N>
typename std::enable_if<!std::is_same<T, char>::value, std::ostream &>::type
operator<<(std::ostream & os, const T (&a)[N]){
    for (size_t i = 0; i < N; ++i)
    {
        os << a[i];
        if(i<N-1){
            cout<<" ";
        }
    }
    os <<endl;
  return os;
}


// less useful prints note that stack and queue modify the info and put it back whereas pq takes nlogn

template<class T, class U>
ostream& operator<<(ostream& os, map<T,U>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<i->first<<": "<<i->second;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    //os<<endl;
    return os;
}
template<class T, class U>
ostream& operator<<(ostream& os, multimap<T,U>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<i->first<<": "<<i->second;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    //os<<endl;
    return os;
}
template<class T>
ostream& operator<<(ostream& os, set<T>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<*i;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    //os<<endl;
    return os;
}
template<class T>
ostream& operator<<(ostream& os, multiset<T>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<*i;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    //os<<endl;
    return os;
}
template<class T>
ostream& operator<<(ostream& os, stack<T>& dt){
    stack<T> t;
    os<<"[";
    while(!dt.empty()){
        T temp=dt.top();
        os<<temp;
        dt.pop();
        t.push(temp);
        if(!dt.empty()){
            os<<", ";
        }
    }
    os<<"]";
    while(!t.empty()){
        T temp=t.top();
        dt.push(temp);
        t.pop();
    }
    //os<<endl;
    return os;
}
template<class T>
ostream& operator<<(ostream& os, queue<T>& dt){
    queue<T> t;
    os<<"[";
    while(!dt.empty()){
        T temp=dt.front();
        os<<temp;
        dt.pop();
        t.push(temp);
        if(!dt.empty()){
            os<<", ";
        }
    }
    os<<"]";
    while(!t.empty()){
        T temp=t.front();
        dt.push(temp);
        t.pop();
    }
    //os<<endl;
    return os;
}
template<class T>
ostream& operator<<(ostream& os, list<T>& dt){
    os<<"[";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<*i;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"]";
    //os<<endl;
    return os;
}
template<class T>
ostream& operator<<(ostream& os, priority_queue<T>& dt){
    queue<T> t;
    os<<"[";
    while(!dt.empty()){
        T temp=dt.top();
        os<<temp;
        dt.pop();
        t.push(temp);
        if(!dt.empty()){
            os<<", ";
        }
    }
    os<<"]";
    while(!t.empty()){
        T temp=t.front();
        dt.push(temp);
        t.pop();
    }
    //os<<endl;
    return os;
}
//here lie the input functions
template <class T=ll>
vector<T> clist(int n){
    std::vector<T> v;
    while(n--){
        T k;
        cin>>k;
        v.push_back(k);
    }
    return v;
}
template<class T=ll, class U=ll>
vector<pair<T,U>> clist2(int n){
    std::vector<pair<T,U>> v;
    while(n--){
        T a;
        U b;
        cin>>a>>b;
        pair<T,U> p(a,b);
        v.push_back(p);
    }
    return v;
}

// this is a special string to vector function
vector<char> cstrtv(string& s){
    vector<char> v;
    for(int i=0; i<s.size(); i++){
        v.push_back(s[i]);
    }
    return v;
}

//turn arrays and strings into frequencies

template<class T>
struct freq{
    //can be turned to set for modifiable acces
    //features:
    //use freq iterators to go over all of m
    //keys of m can directly access freq using []
    //keys can find first and last positions with functions

    // key to array requires call on M
    map<T,vector<int>>m; //can support acess on empty by auto creating an empty vector
    int n;
    freq(vector<T>& s){
        n=s.size();
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])==m.end()){
                vector<int> v;
                m[s[i]]=v;
            }
            m[s[i]].push_back(i);
        }
    }
    freq(string& s){
        n=s.size();
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])==m.end()){
                vector<int> v;
                m[s[i]]=v;
            }
            m[s[i]].push_back(i);
        }
    }
    typename map<T,vector<int>>::iterator begin(){
        return m.begin();
    }
    typename map<T,vector<int>>::iterator end(){
        return m.end();
    }
    int operator[] (T ind){ //supports empty and nulls
        if(m.find(ind)==m.end()){
            return 0;
        }
        return m[ind].size();
    }
    T mode(){ //do not call on empty
        int maxfrq=0;
        T maxel;
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second.size()>maxfrq){
                maxfrq=it->second.size();
                maxel=it->first;
            }
        }
        return maxel;
    }
    int first(T el){
        if(m[el].size()!=0){
            return m[el][0];
        }
        return n;
    }
    int last(T el){
        if(m[el].size()!=0){
            return m[el][m[el].size()-1];
        }
        return -1;
    }
};


//here lie common vector processing functions
template<class T>
int maxind(vector<T>& v){
    int maxi=0;
    for(int i=1; i<v.size(); i++){
        maxi=(v[maxi]<v[i])? i:maxi;
    }
    return maxi;
}
template<class T>
T maxel(vector<T>& v){
    return v[maxind(v)];
}
template<class T>
int minind(vector<T>& v){
    int mini=0;
    for(int i=1; i<v.size(); i++){
        mini=(v[mini]>v[i])? i:mini;
    }
    return mini;
}
template<class T>
T minel(vector<T>& v){
    return v[minind(v)];
}
template<class T>
vector<ll> partialsums(vector<T>& v){
    vector<ll> ps(v.size());
    ps[0]=v[0];
    for(int i=1; i<v.size();i++){
        ps[i]=ps[i-1]+v[i];
    }
    return ps;
}
template<class T>
ll sumy(vector<T>& v){
    ll s=0;
    for(int i=0; i<v.size(); i++){
        s+=v[i];
    }
    return s;
}
template<class T>
vector<int> pminin(vector<T>& v){
    vector<int> ret={0};
    int curi=0;
    for(int i=1; i<v.size(); i++){
        if(v[i]<v[curi]){
            curi=i;

        }
        ret.push_back(curi);
    }
    return ret;
}
template<class T>
vector<int> pmaxin(vector<T>& v){
    vector<int> ret={0};
    int curi=0;
    for(int i=1; i<v.size(); i++){
        if(v[i]>v[curi]){
            curi=i;

        }
        ret.push_back(curi);
    }
    return ret;
}
template<class T>
vector<T> pmin(vector<T>& v){
    vector<T> ret;
    vector<int> temp=pminin(v);
    for(int i=0; i<temp.size(); i++){
        ret.push_back(v[temp[i]]);
    }
    return ret;
}
template<class T>
vector<T> pmax(vector<T>& v){
    vector<T> ret;
    vector<int> temp=pmaxin(v);
    for(int i=0; i<temp.size(); i++){
        ret.push_back(v[temp[i]]);
    }
    return ret;
}

// accessing operators in circular shiz
int ind(int i, int n){
    if(i%n>=0){
        return i%n;
    }
    return (i%n)+n;
}
struct graph{};


// NUMBER THEORY

set<int> divisors(int n){
    set<int> s;
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            // If divisors are equal, print only one
            if (n/i == i){
                s.insert(i);
            }
            else{ // Otherwise print both
                s.insert(i);
                s.insert(n/i);
            }
        }
    }
    return s;
}
freq<int> pf(int n){
    vector<int> s;
    // Print the number of 2s that divide n
    while (n % 2 == 0){
        s.push_back(2);
        n = n/2;
    }
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2){
        // While i divides n, print i and divide n
        while (n % i == 0){
            s.push_back(i);
            n = n/i;
        }
    }
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2){
        s.push_back(n);
    }
    return freq<int>(s);
}
//set to n+1
bool isprime[1];
void seive(int n){
    loop(i,n+1){
        isprime[i]=true;;
    }
    isprime[0]=false;
    isprime[1]=false;
    loop(i,n+1){
        if(isprime[i]){
            for(int j=2*i; j<n+1; j+=i){
                isprime[j]=false;
            }
        }
    }
}

ll modexp(ll n, ll e){
    if(e==0){
        return 1;
    }else{
        if(e%2){
            return (n*(modexp(n,e-1)))%mody;
        }else{
            ll res=modexp(n,e/2);
            return (res*res)%mody;
        }
    }
}
int countbits(ll n){
 ll count = 0;
while (n){
    count += n & 1;
    n >>= 1;
}
return count;
}
void binary(){
    //rg is the one greater than or equal
    // lg is supposedly less than or equal

    /*int lf = 0;
    int rg = n;
    while (rg - lf > 1) {
        int mid = (lf + rg) / 2;
        if(calc(p, mid, x, a, y, b) >= k){
            rg = mid;
        }
        else{
            lf = mid
        }
    } */
}
// bitstring generation and backwards?? combinatorialist function
//add commented out common use functions, look into triplet manipulation as standalone or common. cout over load, comparer overload. bsttt
//cout freq
//learn dbg dp comb
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(__gcd(m,n)!=1){
            cout<<"infinite"<<endl;
        }else{
            cout<<"finite"<<endl;
        }
    }
}
