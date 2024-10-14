import java.util.HashSet;

class Solution {
    public int solution(int[] nums) {
        HashSet<Integer> hash = new HashSet<>();
        
        for (int i : nums) {
            hash.add(i);
        }
        
        int min = nums.length / 2;
        
        if (hash.size() < min) {
            return hash.size();
        } else {
            return min;
        }
        
    }
}