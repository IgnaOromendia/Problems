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
#define remove(set, x) (set &= ~(1 << x))

constexpr int INF  = 1e9;
constexpr int MAXN = 0;
constexpr int mod  = 1e9 + 7;
constexpr double PI = 3.14159265359;

ll target;

bool transform(vector<ll>& sequence) {
    if (sequence.back() == target) {
        cout << "YES\n" <<  sequence.size() << "\n";
        forn(i, 0, sequence.size())
            cout << sequence[i] << " ";
        cout << "\n";
        return true;
    }

    if (sequence.back() > target) return false; 

    sequence.pb(2*sequence.back());
    bool is_possible = transform(sequence);
    sequence.pop_back();

    if (not is_possible) {
        sequence.pb(10*sequence.back() + 1);
        is_possible = transform(sequence);
        sequence.pop_back();
    }

    return is_possible;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int source;

    cin >> source >> target;

    vector<ll> sequence(1, source);

    bool is_possible = transform(sequence);

    if (not is_possible) cout << "NO" << endl;
    
}