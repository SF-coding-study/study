#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    int score1 = 0, score2 = 0, score3 = 0;
    
    vector<int> stu1 = {1, 2, 3, 4, 5};
    vector<int> stu2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> stu3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    // 각 학생의 점수 계산
    for(int i = 0; i < answers.size(); i++) {
        if (answers[i] == stu1[i % stu1.size()]) score1++;
        if (answers[i] == stu2[i % stu2.size()]) score2++;
        if (answers[i] == stu3[i % stu3.size()]) score3++;
    }
    
    // 최대 점수 계산
    int max_score = max({score1, score2, score3});
    
    // 최대 점수를 받은 학생 번호를 저장
    vector<int> answer;
    if (score1 == max_score) answer.push_back(1);
    if (score2 == max_score) answer.push_back(2);
    if (score3 == max_score) answer.push_back(3);
    
    return answer;
}