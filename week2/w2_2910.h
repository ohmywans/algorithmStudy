// BOJ 2910번: 빈도 정렬 - GG
// 오래걸렸는데 세그멘테이션 오류 떠서 결과 확인도 못함
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N, comp;
long long int C;
vector<long long int> v(N);
vector<pair<long long int, int>> vp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C;
	for (int i=0; i<N; i++) {
		cin >> v[i];
	}
	// 원소와 빈도수를 pair로 저장하는 vector 선언, 처리된 원소는 0으로 저장
	for (int i=0; i<N; i++) {
		if (v[i] == 0) continue; // 이미 처리된 값은 건너뜁니다.
		int cnt = 0;
		for (int j=0; j<N; j++) {
			if (v[i] == v[j]) {
				cnt++;
				comp = v[j];
				v[j] = 0; // 초기화
			}
		}
		vp.push_back(make_pair(comp, cnt));
	} 
	// 빈도에 따른 내림차순 정렬
	for (int i=0; i<vp.size(); i++) {
		for (int j=i; j<vp.size(); j++) {
			if (vp[i].second > vp[j].second) {
				swap(vp[i], vp[j]);
			}
		}
	}
	// 출력
	for (int i=0; i<vp.size(); i++) {
		for (int j=0; j<vp[i].second; j++) {
			cout << vp[i].first << " ";
		}
	}
	return 0;
}
// Custom Operator 
#include <bits/stdc++.h>
using namespace std;  
typedef long long ll;
const ll INF = 1e18;   
int n, c, a[1004];
vector<pair<int, int>> v; 
map<int, int> mp, mp_first; // mp: Counting용 map, mp_first: 첫번째 값 할당
bool cmp(pair<int,int> a, pair<int, int> b){
	if(a.first == b.first){
		return mp_first[a.second] < mp_first[b.second];
	}
	return a.first > b.first;
}

// mp : {원소, 빈도} 
// mp_first : {원소, 순위}
// v : {빈도, 원소}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c; 
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mp[a[i]]++;
		if(mp_first[a[i]] == 0) mp_first[a[i]] = i + 1; 
	} 
	// map에서 first, second로 접근하기 위해서는 iterator를 이용해야 한다.
	for(auto it : mp){
		v.push_back({it.second, it.first});
	}
	sort(v.begin(), v.end(), cmp);
	for(auto i : v){
		for(int j = 0; j < i.first; j++){
			cout << i.second << " ";
		}
	} 
	 
	return 0;
}