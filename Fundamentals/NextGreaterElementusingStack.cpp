#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1000000007;
ll inf = INT64_MAX;
double eps = 1e-12;
#define f(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

string string_reverse(string str)
{
    reverse(str.begin(), str.end());
    return str;
}
bool is_lexographically_smaller(string a, string b)
{
    // a<=b
    f(i, 0, a.size())
    {
        if (i < b.size())
        {
            if (a[i] > b[i])
                return false;
            if (a[i] < b[i])
                return true;
        }
        else
            return false;
    }
    return true;
}
v64 make_fibnocci(ll n)
{
    v64 arr(n);
    if (n == 0)
        return {};
    if (n == 1)
        return {1};
    arr[0] = 1;
    arr[1] = 1;
    f(i, 2, n) { arr[i] = (arr[i - 1] % MOD + arr[i - 2] % MOD) % MOD; }
    return arr;
}
ll count_bits(ll n) // for positive numbers
{
    ll count = log2(n);
    return count + 1;
}

string trim(const std::string &s)
{
    auto start = s.begin();
    while (start != s.end() && std::isspace(*start))
    {
        start++;
    }
    auto end = s.end();
    do
    {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));
    return std::string(start, end + 1);
}

/*-------------------------------------------------------------------------------------------------------
Code begins here*/
auto nextGreaterElement(vector<ll> arr)
{
    ll n = arr.size();
    stack<ll> st;
    vector<ll> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            ans[i] = inf;
            st.push(i);
        }
        else
        {
            while (!st.empty() && arr[i] >= arr[st.top()])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans[i] = inf;
                st.push(i);
            }
            else
            {
                ans[i] = st.top();
                st.push(i);
            }
        }
    }

    return ans;
}
int main()
{
    vector<ll> arr = {1, 7, 4, 9, 3, 5, 6, 7, 9, 11, 8, 10};
    auto a = nextGreaterElement(arr);
    auto n = arr.size();
    f(i, 0, n)
    {
        cout << (a[i] != inf ? arr[a[i]] : -1) << " ";
    }

    return 0;
}