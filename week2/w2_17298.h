// BOJ 17298번: 오큰수 - GG(예제는 되는데 시간 초과뜸)
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> v(1000001), ret(1000001);
void go(int now, int idx) {
	if (now >= N-1 || idx >= N) {
		ret[now] = -1; 
		return;
	}
	if (v[now] < v[idx]) ret[now] = v[idx];
	else {
		if (idx + 1 < N) go(now, idx + 1);
        else ret[now] = -1;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < N; i++) {
		go(i, i+1);
	}
	for (int i = 0; i < N; i++) {
		cout << ret[i] << " ";
	}cout << '\n';
	
	return 0;
}

//////////////////////
#include <bits/stdc++.h>
using namespace std; 
int n, a[1000004], ret[1000004];
stack<int> s; 
int main(){
	cin >> n; 
	memset(ret, -1, sizeof(ret));
	for(int i = 0; i < n; i++){
		cin >> a[i];  
		while(s.size() && a[s.top()] < a[i]){
			ret[s.top()] = a[i]; s.pop();
		}
		s.push(i);
	}
	for(int i = 0; i < n; i++) cout << ret[i] << " ";  
} 