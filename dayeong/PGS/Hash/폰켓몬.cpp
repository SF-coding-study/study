#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> nums_map;
    
    for(const int& n : nums){
        nums_map[n]++;
    }
    
    answer = min(nums.size()/2, nums_map.size());
    
    return answer;
}