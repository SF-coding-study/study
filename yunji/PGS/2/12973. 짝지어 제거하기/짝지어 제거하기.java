class Solution {
    public int solution(String s) {
        char[] result = new char[s.length()]; 
        int index = 0; 

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i); 

            if (index > 0 && result[index - 1] == c) {
                index--; // 짝을 제거
            } else {
                result[index] = c; // 새로운 문자 
                index++; 
            }
        }

        // 인덱스가 0이면 모든 문자 제거한
        return index == 0 ? 1 : 0;
    }
}
