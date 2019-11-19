#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vl vector<ll>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll N, K, a;
  std::cin >> N >> K;
  map<ll, ll> num;
  vector<ll> data(300000, 0);
  ll c = 0;
  for(int i=0;i<N;i++){
    std::cin >> a;
    if(num.find(a)==num.end()) {
      num.emplace(a, c);
      data[c]++;
      c++;
    }else{
      data[num.at(a)]++;
    }
  }
  while(K>0&&num.size()!=1){
    auto it_l = num.begin();
    auto it_r = --num.end();
    ll l = data[(*it_l).second];
    ll r = data[(*it_r).second];
    //std::cout << K << '\n';
    //std::cout << (*it_r).first << " " << (*it_l).first<< '\n';
    //std::cout << num.size() << '\n';
    if(l>r){
      ll from = (*it_r).first;
      it_r--;
      ll next = (*it_r).first;
      if((from-next)*r<=K){
        K-=abs(from-next)*r;
        data[num.at(next)]+=r;
        num.erase(from);
      }else{
        ll slide = K/r;
        K = 0;
        num.erase(from);
        num.emplace(from-slide, c);
      }
    }else{
      ll from = (*it_l).first;
      it_l++;
      ll next = (*it_l).first;
      if((next-from)*l<=K){
        K-=abs(from-next)*l;
        data[num.at(next)]+=l;
        num.erase(from);
      }else{
        ll slide = K/l;
        K = 0;
        num.erase(from);
        num.emplace(from+slide, c);
      }
    }
  }
  auto itr = num.begin();
  auto it2 = num.end();
  it2--;

  std::cout << (*it2).first - (*itr).first << '\n';
  return 0;
}
