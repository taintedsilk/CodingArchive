#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

struct qhash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x)
        const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef long long ll;
typedef bool bl;
typedef string str;
typedef unsigned long long ull;
typedef double db;

#define fi first
#define se second
#define mp(p1, p2) make_pair(p1, p2)
#define f(i, n) for (ll i = 0; i < n; i += 1)
#define fv(i, v) for (typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define fu(i, start, end) for (int i = start; i < end; i += 1)
#define fd(i, start, end) for (int i = start; i >= end; i -= 1)
#define BIT(var, pos) ((bool)((var) & (1 << (pos))))
#define pb push_back
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>

#define MOD 1000000007

ll dp[31][2][2];

ll count_pairs(ll t1, ll t2)
{
    f(i, 31) f(j, 2) f(k, 2) dp[i][j][k] = 0;
    vector<bl> x, y;
    while (t1)
    {
        x.push_back(t1 & 1);
        t1 >>= 1;
    }
    while (t2)
    {
        y.push_back(t2 & 1);
        t2 >>= 1;
    }
    while (x.size() < y.size())
        x.push_back(0);
    while (y.size() < x.size())
        y.push_back(0);
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    f(i, max(x.size(), y.size()))
    {
        if (!i)
        {
            dp[0][1][1] = 1;
            dp[0][0][1] = x[i];
            dp[0][1][0] = y[i];
            dp[0][0][0] = x[i] && y[i];
        }
        else
        {
            dp[i][1][1] = 1;
            dp[i][1][0] += dp[i - 1][1][1] * y[i] + dp[i - 1][1][0] * 2;
            dp[i][0][1] += dp[i - 1][1][1] * x[i] + dp[i - 1][0][1] * 2;
            dp[i][0][0] += dp[i - 1][0][0] * 3;
        }
    }

    ll sum = 0;
    f(i, 2) f(j, 2) sum += dp[max(x.size(), y.size()) - 1][i][j];
    return sum;
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    cout << count_pairs(r, r);
    fu(i, 0, 2) {
        f(j, 2) f(k, 2) cout << dp[i][j][k] << " ";
        cout << '\n';
    }
}

int main()
{

    // freopen("pushing.INP", "r" ,stdin); freopen("pushing.OUT", "w", stdout);
    // std::ios_base::sync_with_stdio(0);
    // std::cin.tie(0);
    long long test = 1;

    cin >> test;
    for (int i = 0; i < test; i += 1)
    {
        solve();
    }
    return 0;
}
