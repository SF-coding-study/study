#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 정렬 기준을 정의하는 함수
bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> str_numbers;

    // 숫자들을 문자열로 변환하여 벡터에 저장
    for (int num : numbers) {
        str_numbers.push_back(to_string(num));
    }

    // 사용자 정의 비교 함수로 문자열을 정렬
    sort(str_numbers.begin(), str_numbers.end(), compare);

    // 모든 숫자가 '0'인 경우, "0"을 반환
    if (str_numbers[0] == "0") {
        return "0";
    }

    // 정렬된 문자열을 이어붙여 결과 생성
    for (string num : str_numbers) {
        answer += num;
    }

    return answer;
}