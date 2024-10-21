import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        Map<String, String> pb = new HashMap<>();
        for (String p : phone_book) {
            pb.put(p, p);
        }
        
        for (String p : phone_book) {
            for (int i = 0 ; i < p.length() ; i++) {
                if (pb.containsKey(p.substring(0, i))) {
                    return false;
                }
            }
        }
        return true;
    }
}