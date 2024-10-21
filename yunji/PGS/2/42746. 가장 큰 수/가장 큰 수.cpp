
#include <string>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    string str1=to_string(a)+to_string(b);
    string str2=to_string(b)+to_string(a);
    return str1>str2;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);
    string answer = "";
    for(int i=0; i<numbers.size(); i++)
    {
        answer+=to_string(numbers[i]);
    }
    if(answer[0]=='0')
    {
        return "0";
    }
    return answer;
}