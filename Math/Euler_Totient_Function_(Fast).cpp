#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ln "\n"
using namespace std;

const int LIM = 1009;

typedef vector<ll> vii;
typedef vector<vii> vi;

int test;
ll n;
int us[LIM];
vector<ll> pr;
vi F;

void sieve() {
	memset(us,0,sizeof(us));
	for (int i=2; i<LIM; i++)
		if (us[i] == 0) {
			pr.pb(static_cast<ll>(i));
			us[i] = 1;
			for (int j=2; j*i<LIM; j++) us[i*j] = -1;
		}
}

void init() {
	F.assign(168,vii());
	for (int i=0; i<168; i++) {
		for (ll pp = 1LL; pp < LIM * LIM; pp *= pr[i]) F[i].pb(pp);
	}
}

ll phi(ll n) {
	ll res = 1LL;
	for (int i = 0; i < 168; i++) {
		if (n % pr[i] == 0) {
			int lt,rt,mid,x;
			lt = 0; rt = F[i].size()-1;
			for (int rr = 0; rr < 5; rr++) {
				if (rt - lt < 2) {
					if (n % F[i][rt] == 0) x = rt; else x = lt;
					break;
				} else {
					mid = (lt + rt)/2;
					if (n % F[i][mid] == 0) lt = mid; else rt = mid - 1;
				}
			}
			res *= (F[i][x] - F[i][x-1]);
			n /= F[i][x];
		}
	}
	if (n > 1) res *= (n - 1);
	return res;
}

int main() {
	sieve();
	init();
	scanf("%d",&test);
	while (test--) {
		scanf("%lld",&n);
		printf("%lld\n",phi(n));
	}
}
