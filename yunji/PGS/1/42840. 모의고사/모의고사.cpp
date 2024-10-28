#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int num1[] = {1, 2, 3, 4, 5}; 
    int num2[] = {2, 1, 2, 3, 2, 4, 2, 5}; 
    int num3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; 
    
    int score1 = 0;
    int score2 = 0;
    int score3 = 0;

    for (int i = 0; i < answers.size(); i++) {
        
        if (answers[i] == num1[i % 5]) {
            score1++; 
        }

        if (answers[i] == num2[i % 8]) {
            score2++; 
        }

        if (answers[i] == num3[i % 10]) {
            score3++;
        }
    }

    vector<int> answer;

    if (score1 >= score2 && score1 >= score3) {
        answer.push_back(1); 
    }
    if (score2 >= score1 && score2 >= score3) {
        answer.push_back(2);
    }
    if (score3 >= score1 && score3 >= score2) {
        answer.push_back(3);
    }

    return answer;
}
