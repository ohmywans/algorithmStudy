// BOJ 2309: 일곱 난쟁이
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// <정답 확인>
// 1. 순열 do while 문 이용
// 2. 재귀를 이용한 순열
// 3. pair 이용한 NEW 풀이 - 중첩 for문을 썼는데 9C7 = 9C2의 형태를 이용함. 사실상 응용이지 Not New 풀이임

// 1. 순열 do while 문 이용

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);

	int dwarf[9];
	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
	}
	sort(dwarf, dwarf + 9);
	
	do {
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += dwarf[i];
		}
		if (sum == 100) {
			break;
		}

	} while (next_permutation(dwarf, dwarf + 9));
	
	for (int i = 0; i < 7; i++) {
		cout << dwarf[i] << '\n';
	}
	
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// <정답 확인>
// 1. 순열 do while 문 이용
// 2. 재귀를 이용한 순열
// 3. pair 이용한 NEW 풀이 - 중첩 for문을 썼는데 9C7 = 9C2의 형태를 이용함. 사실상 응용이지 Not New 풀이임

// 2. 재귀를 이용한 순열
int n = 9, r = 7;
int v[9];

void solve() {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		sum += v[i];
	}
	if (sum == 100) {
		// 7까지만 관심 있으니, 여기까지만 sort함. 나머지 둘도 해버리면 애써 만든거 섞여ㅠ
		sort(v, v + 7);
		for (int i = 0; i < r; i++) {
			cout << v[i] << '\n';
		}
		// 이거 대신 return을 해버리면 solve()만 종료됨. exit은 main 함수 자체를 종료시킴
		exit(0);
	}	
}
// 암기하기!!!!
void makePermutation(int n, int r, int depth) {
	
	if (depth == r) {
		solve();
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(v[i], v[depth]);
		makePermutation(n, r, depth + 1);
		swap(v[i], v[depth]);
	}
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 0; i < 9; i++) {
		cin >> v[i];
	}
	makePermutation(n, r, 0);
	return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// <정답 확인>
// 1. 순열 do while 문 이용
// 2. 재귀를 이용한 순열
// 3. pair 이용한 NEW 풀이 - 중첩 for문을 썼는데 9C7 = 9C2의 형태를 이용함. 사실상 응용이지 Not New 풀이임

// 3. pair 이용한 NEW 풀이
int a[9], sum = 0;
pair<int, int> ret; // 9명 중 2명을 뽑을거니까 2명을 뽑는 자료구조인 pair를 사용!
vector<int> v;

void solve() { // 9명 중 2명 뽑을거야~ 중첩 for문 2개~
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < i; j++) {
			if (sum - a[i] - a[j] == 100) {
				ret = {i, j}; // 필요없는 2명은 모두 ret에 들어가
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}
	solve();
	for (int i = 0; i < 9; i++) {
		if (ret.first == i || ret.second == i) { // ret의 첫번째든 두번째든 걸리는 놈 그냥 continue
			continue;
		}
		v.push_back(a[i]); // 두 놈이 아닌 경우만 v에 삽입
	}
	sort(v.begin(), v.end());
	for(int i : v) cout << i << "\n"; 
	
	return 0;
}
*/