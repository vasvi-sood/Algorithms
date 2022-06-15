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
    ll q;
    cin >> n >> q;
    arr.resize(n);
    sumSegmentTree.resize(4 * n);
    f(i, 0, n)
            cin >>
        arr[i];

    buildSumTree(1, 0, n - 1);
    while (q--)
    {
        ll type;
        cin >> type;
        ll l, r, b, x, ans;
        switch (type)
        {
        case 0:

            cin >> l >> r >> b;
            for (ll i = l; i < r; i++)
                update(i, min(arr[i], b));

                     break;
        case 1:

            cin >> l >> r >> b;
            for (ll i = l; i < r; i++)
                update(i, max(arr[i], b));
            break;
        case 2:

            cin >> l >> r >> b;
            for (ll i = l; i < r; i++)
            {
                update(i, arr[i] + b);
            }

            break;
        case 3:

            cin >> l >> r;

            cout << findsum(l, r - 1) << endl;
        }
    }

    return 0;
}