#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int target, int sum, int index){
    int answer = 0; //방법의 수
    
    if(index == numbers.size()){
        if(sum == target){
            return 1;
        }
        else{
            return 0;
        }
    }
    answer += dfs(numbers, target, sum + numbers[index], index+1);
    answer += dfs(numbers, target, sum - numbers[index], index+1);
    
    return answer;
}

int solution(vector<int> numbers, int target) {    
    return dfs(numbers, target, 0, 0);
}