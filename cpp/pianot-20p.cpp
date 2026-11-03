#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string notes;
  cin >> notes;

  set<ll> all_notes;
  for (char c : notes) {
    all_notes.insert(c);
  }

  ll n = sz(all_notes);

  map<char, ll> mapping;
  for (char c : all_notes) {
    mapping[c] = mapping.size();
  }

  vector<ll> permutation(n);
  rep(i, 0, n) {
    permutation[i] = i;
  }

  vector<vector<ll>> cost_matrix(n, vector<ll>(n));
  rep(i, 0, sz(notes) - 1) {
    ll a = mapping[notes[i]];
    ll b = mapping[notes[i + 1]];
    cost_matrix[a][b] += 1;
    cost_matrix[b][a] += 1;
  }

  // Den här loopen går igenom alla möjliga permutationer (ordningar) av talen 0
  // till n - 1
  ll ans = 1e7;
  do {
    ll cost = 0;
    rep(i, 0, n) {
      rep(j, i, n) {
        cost += cost_matrix[permutation[i]][permutation[j]] * abs(i - j);
      }
    }

    ans = min(ans, cost);
  } while (next_permutation(all(permutation)));

  cout << ans << endl;
}
