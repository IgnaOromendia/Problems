#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<int> > mat;
typedef vector<vector<int> > graph;
typedef pair<int,int> pi;
typedef pair<double,double> pd;

#define pb push_back
#define mp make_pair

#define forn(i, from, to) for (int i = from; i < to; i++)
#define rforn(i, from, to) for (int i = from; i >= to; i--)

// Bitset
#define contains(set, x) (set & (1 << x))
#define add(set, x) (set |= (1 << x))
#define set_size(set) __builtin_popcount(set)
#define remove(set, x) (set &= ~(1 << x))

constexpr ll INF  = 1e18;
constexpr int MAXN = 1e5 + 1;
constexpr int mod  = 1e9 + 7;
constexpr double PI = 3.14159265359;

int n;
vll cost;
vector<string> word, rword;
ll memo[MAXN][2];

// last nos dice si el i-1 fue invertido o no 
ll min_cost(int i, bool last) {
    if (i == n) return 0;

    if (memo[i][last] != -1) return memo[i][last];

    string& last_word = last ? rword[i-1] : word[i-1];

    memo[i][last] = INF;

    if (word[i] >= last_word)
        memo[i][last] = min(memo[i][last], min_cost(i+1, false));

    if (rword[i] >= last_word)
        memo[i][last] = min(memo[i][last], cost[i] + min_cost(i+1, true));

    return memo[i][last];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n;

    n++;

    cost.resize(n);
    word.resize(n);
    rword.resize(n);

    word[0] = "";
    rword[0] = "";

    forn(i,1,n) 
        cin >> cost[i];

    forn(i,1,n) {
        cin >> word[i];
        rword[i] = string(word[i].rbegin(), word[i].rend());
    }    

    ll cost = min_cost(1, false);

    if (cost >= INF) {
        cout << "-1\n";
        return 0;
    }

    cout << cost << endl;
}