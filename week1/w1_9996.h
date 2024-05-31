/* BOJ 9996번: 한국이 그리울 땐 서버에 접속하지
// 내가 푼 것: 런타임 에러 / 스승님 코드와 마지막 답을 내는 과정상 시간 차이가 있었음
// (반례로 size() 크기 비교하는 것 없으면, input: ab*ab 일 때, ab 이면 NE여야 하는데 DA로 나옴)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 파일의 개수 N, 패턴 Pattern 입력
	int N;
	string Pattern;
	cin >> N;
	cin >> Pattern;

	// 구분자인 *의 위치를 pos에 저장
	int pos = Pattern.find('*');
	string first = Pattern.substr(0, pos); // pos 위치 전까지 다 받아옴
	string last = Pattern.substr(pos + 1); // pos+1 위치부터 끝까지 다 저장
	
	// 크기가 N인 파일들로 이루어진 벡터 Files에 요소 입력
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		
		// 이 부분이 스승님 코드, 내가 반례 처리를 안해서 틀린 것이다. 
		if(first.size() + last.size() > s.size()){
		cout << "NE\n";
		} else{
		if(first == s.substr(0, first.size()) && last == s.substr(s.size() - last.size())) cout << "DA\n";
		else cout <<"NE\n";  
		}
		
		// // 아래가 내가 짠 코드인데 testcase는 모두 맞음. 로직도 맞는데 런타임 에러 발생
		// string compFirst = s.substr(0, first.size());
		// string compSecond = s.substr(s.size()-last.size(), s.size());
		
		// if (first == compFirst && last == compSecond) {
		// 	cout << "DA" << '\n';
		// } else {
		// 	cout << "NE" << '\n';
		// }
	}
    return 0;
}
*/