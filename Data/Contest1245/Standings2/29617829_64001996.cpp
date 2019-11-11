#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string s;
int n;

const int md = 1000000007;
int d[100010];

int32_t main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    d[0] = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'w' or s[i] == 'm'){
            cout << 0 << endl;
            return 0;
        }
        d[i+1] += d[i];
        if(d[i+1] >= md) d[i+1] -= md;
        if(i){
            if(s[i] == 'u' && s[i-1] == 'u' || s[i] == 'n' && s[i-1] == 'n'){
                d[i+1] += d[i-1];
                if(d[i+1] >= md) d[i+1] -= md;
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}
