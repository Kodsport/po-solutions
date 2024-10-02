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

vector<string> plates;
ll n, m;

ll count(ll plate_nr, string mask) {
  if (plate_nr == n) {
    return mask.find('.') != string::npos;
  }

  ll total_count = 0;
  for (ll offset = 0; offset < m; offset++) {
    string new_mask;
    for (ll i = 0; i < m; i++) {
      if (mask[i] == '.' && plates[plate_nr][(i + offset) % m] == '.') {
        new_mask.push_back('.');
      } else {
        new_mask.push_back('#');
      }
    }
    total_count += count(plate_nr + 1, new_mask);
  }

  return total_count;
}

int main() {
  fast();

  cin >> n >> m;

  plates.resize(n);
  for (ll i = 0; i < n; i++) {
    cin >> plates[i];
  }

  cout << count(0, string(m, '.')) << endl;

  return 0;
}
