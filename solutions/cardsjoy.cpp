#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > mat;
typedef vector<vector<int> > graph;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef unordered_map<int,int> umap;

#define pb push_back
#define mp make_pair

#define forn(i, from, to) for (int i = from; i < to; i++)
#define rforn(i, from, to) for (int i = from; i >= to; i--)

// Bitset
#define contains(set, x) (set & (1 << x))
#define add(set, x) (set |= (1 << x))
#define set_size(set) __builtin_popcount(set)
#define remove(set, x) (set &= ~(1 << x))

constexpr int INF  = 1e9;
constexpr int MAXN = 500;
constexpr int MAXK = 10;
constexpr int mod  = 1e9 + 7;
constexpr double PI = 3.14159265359;

int n, k;
ll memo[MAXK*MAXN + 1][MAXN + 1];
vi h;

// Max felicidad con c cartas del mismo número para n personas
ll max_h(int c, int n) {
    if (c <= 0 or n == 0) return 0;

    if (memo[c][n] != -1) return memo[c][n];

    memo[c][n] = 0;
    forn(t, 0, min(c, k) + 1) {
        ll give = h[t] + max_h(c - t, n-1);
        memo[c][n] = max(memo[c][n], give);
    }

    return memo[c][n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    umap card_amount, fans;

    cin >> n >> k;

    h.resize(k+1);
    
    forn(i, 0, n*k) {
        int c; cin >> c;
        card_amount[c]++;
    }

    forn(i, 0, n) {
        int f; cin >> f;
        fans[f]++;
    }

    forn(i, 1, k+1) cin >> h[i];

    ll res = 0;

    // Por cada carta vemos el mejor escenario posible 
    for (auto& [card, people] : fans) {
        memset(memo, -1, sizeof(memo));
        res += max_h(card_amount[card], people);
    }

    cout << res << "\n";
}