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
#define size(set) __builtin_popcount(set)
#define remove(set, x) (set &= ~(1 << x))

constexpr int INF  = 1e9;
constexpr int MAXN = 0;
constexpr int mod  = 1e9 + 7;
constexpr double PI = 3.14159265359;

int min_moves(string& s, int i, int j, char c) {
    if (j - i == 1) return s[i] != c;

    int m = (i+j) / 2;

    int left_diff = 0, right_diff = 0;

    forn(k, i, m) left_diff  += s[k] != c;
    forn(k, m, j) right_diff += s[k] != c;

    int left    = right_diff + min_moves(s, i, m, c + 1);
    int right   = left_diff  + min_moves(s, m, j, c + 1);

    return min(left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        string word; cin >> word;

        cout << min_moves(word, 0, n, 'a') << "\n";
    }
}