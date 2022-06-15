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
vector<ll> arr;
ll n;
vector<ll> sumSegmentTree;
void buildSumTree(ll node, ll start, ll end)
{
    if (start == end)
    {
        sumSegmentTree[node] = arr[start];
        return;
    }
    ll mid = (start + end) / 2;
    ll left = 2 * node, right = left + 1;
    buildSumTree(left, start, mid);
    buildSumTree(right, mid + 1, end);
    sumSegmentTree[node] = sumSegmentTree[left] + sumSegmentTree[right];
}
ll findsum(ll l, ll r, ll start, ll end, ll node)
{
    if (end < l || start > r)
        return 0;
    if (start >= l && end <= r)
        return sumSegmentTree[node];
    ll mid = (start + end) / 2;
    ll rightsum = findsum(l, r, start, mid, 2 * node);
    ll leftsum = findsum(l, r, mid + 1, end, 2 * node + 1);
    return leftsum + rightsum;
}
ll findsum(ll l, ll r)
{
    return findsum(l, r, 0, n - 1, 1);
}
void update(ll idx, ll val, ll start, ll end, ll node)
{
    ll mid = (start + end) / 2;
    if (start == end)
    {
        arr[start] = val;
        sumSegmentTree[node] = val;
        return;
    }
    if (idx <= mid)
        update(idx, val, start, mid, 2 * node);
    else
        update(idx, val, mid + 1, end, 2 * node + 1);
    sumSegmentTree[node] = sumSegmentTree[2 * node] + sumSegmentTree[2 * node + 1];
}
void update(ll idx, ll val)
{
    update(idx, val, 0, n - 1, 1);
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    while (t--)
    {
        arr = {1, 2, 5, 3, 7, 3, 9, 10, 5};
        n = arr.size();
        sumSegmentTree.resize(4 * n, 0);
        buildSumTree(1, 0, n - 1);
        f(i, 1, 4 * n)
                cout
            << sumSegmentTree[i] << " ";
        cout << endl;

        ll ans1 = findsum(0, 7);
        ll ans2 = findsum(6, 8);
        ll ans3 = findsum(3, 7);
        ll ans4 = findsum(0, n - 1);

        cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
        update(3, 6);
        cout << findsum(0, 8) << endl;
    }
    return 0;
}