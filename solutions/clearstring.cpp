#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
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
#define set_remove(set, x) (set &= ~(1 << x))

constexpr int INF  = 1e9;
constexpr int MAXN = 501;
constexpr int mod  = 1e9 + 7;
constexpr double PI = 3.14159265359;

string word;
mat memo;

int min_op(int l, int r) {
    if (l == r) return 1;
    if (l > r) return 0;

    if (memo[l][r] != -1) return memo[l][r];

    memo[l][r] = 1 + min_op(l+1, r);

    forn(k, l+1, r+1) 
        if (word[l] == word[k])
            memo[l][r] = min(memo[l][r], min_op(l+1, k - 1) + min_op(k, r));

    return memo[l][r];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n >> word;

    memo.assign(n+1, vi(n+1, -1));

    cout << min_op(0, n-1) << "\n";
    
}