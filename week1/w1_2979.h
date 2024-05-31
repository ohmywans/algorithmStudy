// BOJ 2979번: 트럭 주차
// 정답 코드와 로직이 정확히 일치해서 패스

#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int A, B, C;
	cin >> A >> B >> C;
	
	int arrived, gone;
	int Time[100] = { 0 };
	
	// 입력 3번 받고, 받을 때마다 초기화된 배열에 index의 시작~끝-1 해당되는 곳에 1씩 증가
	for (int i = 0; i < 3; i++) {
		cin >> arrived >> gone;
		for (int i = arrived; i < gone; i++) {
			Time[i]++;
		}
	}
	// 저장된 값이 1이면 입력받은 A만큼, 2이면 2B, 3이면 3C만큼 누적 합
    int sum = 0;
	for (int i = 0; i < 100; i++) {
		if (Time[i] == 1) { sum += A; }
		else if (Time[i] == 2) { sum += 2 * B; }
		else if (Time[i] == 3) { sum += 3 * C; }
	}
	cout << sum << '\n';

    return 0;
}
