/* BOJ 1940번: 주몽 - 재귀 풀이: 시간 초과 / 중첩 for문 풀이: 정답
정답 코드와 로직이 같은 편이지만, 중간에 예외 처리로 넣으신 부분을 짚고 넘어갈 필요가 있어 달아둠

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count = 0;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N; // 재료의 개수
	cin >> M; // 갑옷 만드는데 필요한 수
	
	vector<int> b;
	vector<int> armorNum(N);
	for (int i = 0; i < N; i++) {
		cin >> armorNum[i];
	}
	
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) {
			sum = armorNum[i] + armorNum[j];
			if (sum == M) {
				count++;
			}
		}
	}
	cout << count << '\n';
    return 0;
}
*/

/*
#include<bits/stdc++.h> 
using namespace std;     
int n, m, a[15001], cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m; 
	
	// N 크기 배열에 갑옷 수 각각 저장
	for(int i = 0; i < n; i++) cin >> a[i]; 
	
	//이 if문은 없어도됨. but, 설명을 위해.
	if(m > 200000) cout << 0 << "\n";
	else{
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(a[i] + a[j] == m)cnt++;
			}
		}
		cout << cnt << "\n";
	} 
}
*/