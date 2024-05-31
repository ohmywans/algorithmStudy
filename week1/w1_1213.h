/* BOJ 1213번: 팰린드롬 만들기 - 알파벳 개수 배열 만들어서 홀, 짝 나누어 분석하고,
//							  first + middle + second 로 나누어 마지막에 합침
//정답 코드: 나와 생각은 같음. 코드가 단순화 되어있고, 많이 절제된 느낌. ret 부분은 내가 직접 구현하기 힘들 듯

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;
	int sSize = s.size();
	
	// 대문자만 들어오니까 해당하는 알파벳 개수만큼 1 증가하는 배열 생성
	int alphabet[26] = { 0 };
	for (int i = 0; i < sSize; i++) {
		alphabet[s[i] - 65]++;
	}
	
	string middle = "";
	// s의 길이가 홀수이면 middle 저장하는 사전 작업 필요
	if (sSize % 2 == 1) {
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] % 2 == 1) {
				middle = (char)(i + 65);
				alphabet[i]--;
				break;
			}
		}
	}
	// s의 길이가 middle 제외하고, 전부 짝수인 상태
	string first = "";
	string second = "";
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] % 2 == 0) {
			for (int j = 0; j < alphabet[i]/2; j++) {
				second += (char)(i + 65);
			}
		}
	}
	// first에 second 복사하고, second는 역순으로 만들기
	first = second;
	reverse(second.begin(), second.end());
	
	string answer = "";
	answer = first + middle + second;
	
	if (answer.size() != sSize) {
		cout << "I'm Sorry Hansoo" << '\n';
	} else cout << answer << '\n';
	
	return 0;
}
*/
/* reverse 없이 팰린드롬 만드심
#include<bits/stdc++.h> 
using namespace std; 

string s, ret; 
int cnt[200], flag; 
char mid;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	
	// 크기가 200인 cnt 배열에 알파벳 하나하나의 아스키 값인 위치에 1씩 증가 (결국 그 문자가 홀수 or 짝수 개수인지 중요해서 카운팅 사용)
	for(char a : s) cnt[a]++;
	
	// (**) cnt 배열의 요소 i가 Z부터 A까지 작아지면서 
	// -> 오름차순으로 앞 덩어리 + mid + 내림차순 뒷 덩어리니까 Z부터 mid 중심으로 더해가기 위해 Z부터 A로 줄여가는 반복문 사용
	for(int i = 'Z'; i >= 'A'; i--){
		
		// cnt 배열에 값이 존재하면
		if(cnt[i]){
			
			// cnt 배열의 값이 홀수라면 mid에 그 요소 저장하고, cnt 배열 값 1 감소, flag 1 증가
			if(cnt[i] & 1){
				mid = char(i);flag++;
				cnt[i]--;
			}
			// flag = 2: 알파벳의 수가 홀수인 경우가 2개라는 거니까 팰린드롬 만들 수 없어서 break
			if(flag == 2)break;
			
			// j는 2씩 증가하면서 i 위치의 값을 알파벳으로 변환하여 ret에 누적하여 저장
			for(int j = 0; j < cnt[i]; j += 2){
				ret = char(i) + ret; // ret => Z + ret 되고
				ret += char(i);		 // ret => Z + ret + Z 돼
			} // => Z를 2개 쓰게 되니까 for문에서 j를 2개 더 증가시키면서 알파벳 수가 더 있으면 3번째부터 다시 양쪽에 1개씩 총 2개 붙여라 ~는 뜻
		}
	} 
	// mid에 값이 존재하면, 중간 위치에 mid 삽입
	if(mid)ret.insert(ret.begin() + ret.size() / 2, mid);
	
	// flag 2이면 팰린드롬 안됨
	if(flag == 2)cout << "I'm Sorry Hansoo\n";
	// 그렇지 않으면 완성된 ret 출력
	else cout << ret << "\n"; 
}
*/