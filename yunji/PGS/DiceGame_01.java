public class DiceGame_01 {
    public static void main(String[] args) {
        Solution solution = new DiceGame_01().new Solution();

        // 입력값
        int a = 1; // 첫 번째 주사위
        int b = 1; // 두 번째 주사위
        int c = 1; // 세 번째 주사위
        int d = 1; // 네 번째 주사위

        int result = solution.solution(a, b, c, d);
        System.out.println("결과: " + result);
    }

    class Solution {
        public int solution(int a, int b, int c, int d) {
            int answer = 0;
            int q = 0;

            if(a == b && b == c && c == d){
                answer = 1111 * a;
            }

            else if((a==b && a==c && d!=a) || (a==b && a==d && c!=a) || (a==c && a==d && b!=a) || (b==c && b==d && a!=b)){
                if(a==b && a==c){
                    answer = (10 * a + d) * (10 * a + d);
                }
                else if(a==c && c==d){
                    answer = (10 * a + b) * (10 * a + b);
                }
                else if(b==c && c==d){
                    answer = (10 * b + a) * (10 * b + a);
                }
                else if(b==d && d==a){
                    answer = (10 * b + c) * (10 * b + c);
                }
            }

            else if((a==b && c==d) || (a==c && b==d) || (a==d && b==c)){
                if(a==b && c==d){
                    answer = (a + c) * Math.abs(a-c);
                }
                else if(a==c && b==d){
                    answer = (a + b) * Math.abs(a-b);
                }else if(a==d && b==c){
                    answer = (a + b) * Math.abs(a-b);
                }
            }

            else if((a==b && c != d) || (a==c && b != d) || (a==d && b != c) ||
                    (b==c && a != d) || (b==d && a != c) || (c==d && a != b)){
                if(a==b && c != d){
                    answer = c * d;
                }else if(a==c && b!=d){
                    answer = b *d;
                }else if(a==d && c!=b){
                    answer = c *b;
                }else if(b ==c && a!=d){
                    answer = a *d;
                }else if(c==d && a!=b){
                    answer = a *b;
                }else if(b==d && a!=c){
                    answer = a *c;
                }
            }

            else{
                answer=Math.min(a,b);
                answer=Math.min(answer,c);
                answer=Math.min(answer,d);
            }

            return answer;
        }
    }
}
