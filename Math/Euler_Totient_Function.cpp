#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ln "\n"
using namespace std;

const int LIM = 1000009;

int test;
ll n;
int us[LIM];
vector<ll> pr;

void sieve() {
	memset(us,0,sizeof(us));
	for (int i=2; i<LIM; i++)
		if (us[i] == 0) {
			pr.pb(i);
			us[i] = 1;
			for (int j=2; j*i<LIM; j++) us[i*j] = -1;
		}
}
 
ll phi(ll n) {
	ll res = n;
	for (int i=0; i<pr.size(); i++) {
		ll p=pr[i];
		if (n%p==0) {
			res/=p; res*=(p-1);
			while (n%p==0) n/=p;
		}
	}
	if (n>1) {
		res/=n; res*=(n-1);
	}
	return res;
}

int main() {
	sieve();
	scanf("%d",&test);
	while (test--) {
		scanf("%lld",&n);
		printf("%lld\n",phi(n));
	}
}
