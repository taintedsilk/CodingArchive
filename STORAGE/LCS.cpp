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
str a, b;
ll dp[1000];
ll cnt[1000];
ll val[255];
ll update[255];
ll id = 0, n, m;

void solve()
{
    cin >> a >> b;
    n = a.size(), m = b.size();
    f(i, 1000) cnt[i] = 1;
    f(i, m) {
        ll highest = 1;
        ll total = 1;
        f(j, n) {
            if (b[i] == a[j]) {
                if (dp[j] == highest + 1) {
                    swap(total, cnt[j]);
                    highest += 1;
                }
                else {
                    dp[j] = highest + 1;
                    cnt[j] = total;
                }
            } 
            else if (dp[j] > highest) {
                highest = dp[j];
                total = cnt[j];
                val[a[j]] = cnt[j];
                update[a[j]] = ++id;
            }
            else if (dp[j] == highest) {
                
                if (update[a[j]] != id) 
                    val[a[j]] = 0, update[a[j]] = id;
                total -= val[a[j]];
                //if (i == 1 && j == 0) cout << val[a[j]];
                val[a[j]] = max(val[a[j]], cnt[j]);
                total += val[a[j]];
                
            }
        }
        f(j, n) cout << dp[j] << " ";
        cout << '\n';
        f(j, n) cout << cnt[j] << " ";
        cout << '\n';
    }
    map<char, bl>M;
    ll res = -1;
    ll res_cnt = 0;
    f(i, n) {
        if (dp[i] > res) {
            res = dp[i];
            M.clear();
            res_cnt = cnt[i];
            M[a[i]] = cnt[i];
        }
        else if (dp[i] == res) {
            res_cnt -= M[a[i]];
            res_cnt += cnt[i];
            M[a[i]] = cnt[i];
        }
    }
    cout << res - 1 << " " << res_cnt << '\n';
}

int main()
{
    // freopen("pushing.INP", "r" ,stdin); freopen("pushing.OUT", "w", stdout);
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    long long test = 1;

    // cin >> test;
    for (int i = 0; i < test; i += 1)
    {
        solve();
    }
    return 0;
}
