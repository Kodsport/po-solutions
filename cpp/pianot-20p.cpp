#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define per(i, high) for (int i = high - 1; i >= 0; i--)
#define perr(i, high, low) for (int i = high - 1, i >= low; i++)
#define sz(container) ((int)container.size())
#define all(x) begin(x), end(x)

void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

int main() {
  fast();

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
  for (ll i = 0; i < n; i++) {
    permutation[i] = i;
  }

  vector<vector<ll>> cost_matrix(n, vector<ll>(n));
  for (ll i = 0; i < sz(notes) - 1; i++) {
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
    for (ll i = 0; i < n; i++) {
      for (ll j = i; j < n; j++) {
        cost += cost_matrix[permutation[i]][permutation[j]] * abs(i - j);
      }
    }

    ans = min(ans, cost);
  } while (next_permutation(all(permutation)));

  cout << ans << endl;

  return 0;
}
