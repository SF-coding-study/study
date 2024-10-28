#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int tmp = brown / 2 - 2;
    int height = 0;
    int width = 0;
    
    while(width >= height){
        height++;
        
        width = tmp - height;
        
        if(height * width == yellow){
            answer.push_back(width + 2);
            answer.push_back(height + 2);
            break;
        }
    }
    
    return answer;
}