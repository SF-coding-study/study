#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

 unordered_map<string, int> participantCount; 

    for (int i = 0; i < participant.size(); i++) { 
        string name = participant[i]; 
        participantCount[name]++; 
    }

    for (int i = 0; i < completion.size(); i++) { 
        string name = completion[i]; 
        participantCount[name]--; 
    }


    for (const auto& entry : participantCount) { 
        string name = entry.first; 
        int count = entry.second; 

        if (count > 0) { 
            return name; 
        }
    }

    return 0; 
}