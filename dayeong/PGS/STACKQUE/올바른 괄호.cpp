#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true; 
    queue<char> q;
    int count = 0;
    
    for (int i = 0; i < s.length(); i++){
        q.push(s[i]);
    }
    
    while(!q.empty()){
        if(q.front() == '(')
            count++;
        else{
            count--;
            if(count < 0){
                return false;
            }
        }
        q.pop();
    }
    
    if(count != 0)
        answer = false;
    
    return answer;
}