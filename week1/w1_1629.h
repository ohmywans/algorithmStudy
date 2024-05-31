/* BOJ 1629번: 곱셈 - 시간 초과 (유명한 문제이자 풀이)
 * 1. 가장 먼저 볼 것이 뭐라고? 최대, 최소 범위!
 * A, B, C는 모두 20억 이하. 
 * 그러므로 이를 for문으로 접근하면 시간 복잡도가 20억이 나올 것이므로 for문으로 접근하지 말아야지! 해야돼
 * 무분별한 for문보다 구조적인 재귀 형태가 더 낮은 시간 복잡도로 계산될 수 있다!
// Test case 입력 후 엔터치고 Ctrl + D 키 누르면 EOF 수동 입력 가능 
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll a, b, c;
// 재귀함수 구현
ll go(ll a, ll b){
	// 기저 사례
    if(b == 1) return a % c;
	
	// ret에 'a의 b/2승을 계산한 걸 담아두고'
    ll ret = go(a, b / 2);
	// ret을 두 번 곱해서 연산량을 줄여준 상태에서 C와 모듈러 연산
    ret = (ret * ret) % c;
	// b가 홀수이면 a가 한 번 덜 곱해졌었을테니 한번 더 곱해서 C와 모듈러 연산한다
	if(b % 2)ret = (ret * a)% c;
	
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    cout << go(a, b) << "\n";
    return 0;
}
*/