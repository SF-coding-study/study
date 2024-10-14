import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> map = new HashMap<>();
        for (String pt : participant) {
            map.put(pt, map.getOrDefault(pt, 0) + 1);
        }
        
        for (String cp : completion) {
            map.put(cp, map.get(cp) - 1);
        }
        
        for (String res : map.keySet()) {
            if (map.get(res) == 1) {
                return res;
            }
        }
        return "";
    }
}