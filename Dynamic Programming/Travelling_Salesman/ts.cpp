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
ll MOD = 998244353;
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
int min_cost_path(int parent, vector<vector<int>> &arr, int node, vector<int> child)
{
    if (child.size() == 0)
        return arr[node][parent];

    int mn = INT32_MAX;
    for (auto k : child)
    {
        vector<int> sub_child(child.size() - 1);
        int p = 0;
        for (auto j : child)
        {
            if (j != k)
            {
                sub_child[p] = j;
                p++;
            }
            // cout << "sub child ok " << node << endl;
        }
        mn = min(mn, arr[node][k] + min_cost_path(parent, arr, k, sub_child));
    }
    return mn;
}
int main()
{
    fast_cin();
    int n = 4;
    vector<vector<int>> arr(n, vector<int>(n));
    arr[0][0] = 0;
    arr[0][1] = 10;
    arr[0][2] = 15;
    arr[0][3] = 20;

    arr[1][0] = 5;
    arr[1][1] = 0;
    arr[1][2] = 9;
    arr[1][3] = 10;

    arr[2][0] = 6;
    arr[2][1] = 13;
    arr[2][2] = 0;
    arr[2][3] = 12;

    arr[3][0] = 8;
    arr[3][1] = 8;
    arr[3][2] = 9;
    arr[3][3] = 0;
    int mn = min_cost_path(0, arr, 0, {1, 2, 3});
    cout << mn << endl;
    mn = min_cost_path(3, arr, 3, {0, 1, 2});
    cout << mn << endl;
    return 0;
}