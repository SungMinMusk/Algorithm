/*
  문제 : https://www.acmicpc.net/problem/2870
  풀이 : 문자열에서 숫자만 찾아 붙여나가고 정렬해준다. 
*/

import java.math.BigInteger;
import java.util.*;
public class Main{
    public static boolean isNum(char a) {
        if(a>='0' && a<='9') {
            return true;
        }
        return  false;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n;
        ArrayList<BigInteger> v = new ArrayList<BigInteger>();
        n = sc.nextInt();
        for(int z=1;z<=n;z++) {
            String s = sc.next();
            for (int i = 0; i < s.length(); i++) {
                String num = "";
                while (i < s.length() && isNum(s.charAt(i))) {
                    num += s.charAt(i);
                    i++;
                }
                if(num != "") {
                    v.add(new BigInteger(num));
                }
            }
        }
        Collections.sort(v);
        for(BigInteger i : v) System.out.println(i);
    }
}
