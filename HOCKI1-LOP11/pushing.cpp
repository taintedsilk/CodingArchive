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

#define MAXN 2004
ll n, m;
str arr[21];
ll player_step[21][21][4];
ll box_step[21][21];
ll dx[] = {-1, 0, 0, 1};
ll dy[] = {0, 1, -1, 0};
pair<ll, ll>player_loc;
struct DATA {
    ll x, y;
    int dir;
    DATA(ll x, ll y, int dir) :
        x{x}, y{y}, dir{dir} {}

};
bl inside(ll i, ll j)
{
    return (i >= 0 && j >= 0 && i < MAXN && j < MAXN);
}
ll PlayerBFS(pair<ll, ll>start, pair<ll, ll>box_loc, pair<ll, ll>dest)
{
    if (arr[start.fi][start.se] == 'X') return 0;

    queue<pair<ll, ll>>q;
    q.push(start);
    arr[box_loc.fi][box_loc.se] = 'X';
    vector<vector<ll>>check(21, vector<ll>(21));
    check[start.fi][start.se] = 1;
    while (q.size())
    {
        pair<ll, ll>cur = q.front();
        q.pop();
        f(k, 4)
        {
            ll x = cur.fi + dx[k], y = cur.se + dy[k];
            if (inside(x, y) && !check[x][y] && arr[x][y] != 'X')
            {
                check[x][y] = check[cur.fi][cur.se] + 1;
            }
        }
    }
    arr[box_loc.fi][box_loc.se] = '.';
    return check[dest.fi][dest.se];

}
queue<DATA>q;
void boxBFS(ll i, ll j)
{
    
    while (q.size())
    {
        DATA cur = q.front();
        q.pop();
        f(k, 4)
        {
            ll x1 = cur.x + dx[k], y1 = cur.y + dy[k];
            ll x2 = cur.x - dx[k], y2 = cur.y - dy[k];
            if (inside(x1, y1) && inside(x2, y2))
            {
                if (!box_step[x1][y1] || box_step[x1][y1] == (box_step[cur.x][cur.y] + 1)) {
                    ll val = PlayerBFS({cur.x + dx[cur.dir], cur.y + dy[cur.dir]},
                              {cur.x, cur.y}, {x2, y2});
                    if (val)
                    {
                        box_step[x1][y1] = box_step[cur.x][cur.y] + 1;
                        player_step[x1][y1][3 - k] = min(player_step[x1][y1][3 - k], player_step[cur.x][cur.y][cur.dir] + val);
                    }

                }
            }
        }

    }
}
void solve()
{
    cin >> n >> m;
    f(i, n)
    {
        cin >> arr[i];
    }
    fill_n(&player_step[0][0][0], 21 * 21 * 4, LLONG_MAX);

    f(i, n) {
        f(j, m) {
            if (arr[i][j] == 'B') {
                f(k, 4) {
                    ll val
                    q.push(DATA(i, j, k));
                }
                
                
            }
        }
    }





}
int main()
{

    //freopen("SUMC.INP", "r" ,stdin); freopen("SUMC.OUT", "w", stdout);
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    long long test = 1;

    //cin >> t;
    for (int i = 0; i < test; i += 1)
    {
        solve();
    }
    return 0;
}
