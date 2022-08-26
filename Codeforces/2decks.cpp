#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

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

//unordered_set<double, custom_hash>s;
#define MOD 1000000007


typedef long long ll;
typedef bool bl;
typedef string str;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef unordered_map<ll, ll, qhash> llumap;
typedef map<ll, ll> llmap;

#define it1 it->first
#define it2 it->second
#define fi first
#define se second
#define mp(p1, p2) make_pair(p1, p2)
#define f(i, n) for (ll i = 0; i < n; i += 1)
#define F(i, n, inc) for (ll i = 0; i < n; i += inc)
#define fu(i, start, end) for (int i = start; i < end; i += 1)
#define Fu(i, start, end, inc) for (int i = start; i < end; i += inc)
#define fd(i, start, end) for (int i = start; i >= end; i -= 1)
#define Fd(i, start, end, inc) for (int i = start; i >= end; i -= inc)
#define itr iterator
#define BIT(var,pos) ((var) & (1<<(pos)))
//#define ordered_set tree<pair<ll, ll>, null_type,less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
map<ll, map<ll, vector<bl>>>M;
int arr[100001][31];

void change(ll i, ll j)
{
    if (!arr[i][j]) return;
    else
    {
        arr[i][j] = 0;
        for (auto it : M[i])
        {
            if (it.se[j]) arr[it.fi][j] = 1;
        }
    }
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    f(i, n + 1)
    f(j, 31) arr[i][j] = 2;
    ll a, b, c;
    queue<pair<ll, ll>>qe;
    f(i, q)
    {
        cin >> a >> b >> c;
        vector<bl>bit;
        f(j, 31)
        {
            bit.push_back(c & 1);
            c /= 2;
        }
        if (a == b)
        {
            f(j, 31)
            {
                if (bit[j])
                    arr[a][j] = 1;
                else
                    qe.push({a, j});
            }
        }
        else
        {
            M[a][b] = bit;
            M[b][a] = bit;
            f(j, 31)
            {
                if (!bit[j])
                {
                    qe.push({a, j});
                    qe.push({b, j});
                }
            }
        }
    }
    while (qe.size()) {
        change(qe.front().fi, qe.front().se);
        qe.pop();
    }
    fu(i, 1, n + 1)
    {
        f(j, 31)
        {
            if (arr[i][j] == 2)
            {
                change(i, j);
            }
        }
    }
    fu(i, 1, n + 1)
    {
        ll total = 0;
        ll cur = 1;
        f(j, 31)
        {
            total += cur * arr[i][j];
            cur *= 2;
        }
        cout << total << " ";
    }




}


int main()
{

    //freopen("SUMC.INP", "r" ,stdin); freopen("SUMC.OUT", "w", stdout);
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    long long test = 1;

    //cin >> test;
    for (int i = 0; i < test; i += 1)
    {
        solve();
    }
    return 0;
}
