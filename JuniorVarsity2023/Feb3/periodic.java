import java.io.*;
public class periodic {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int len = str.length();
        for (int k = 1; k <= len; k++) {
            boolean works = false;
            if (len%k == 0) {
                works = true;
                for (int i = 0; i <= len-k-1; i += k) {
                    String sub1 = str.substring(i, i+k);
                    String sub2 = str.substring(i+k, i+k*2);

                    
                    int ss1 = 0, ss2 = 1;
                    for (int j = 0; j < k; j++) {
                        ss1 %= k;
                        ss2 %= k;
                        if (sub1.charAt(ss1) != sub2.charAt(ss2)) {
                            works = false;
                            break;
                        }
                        ss1++;
                        ss2++;
                    }
                    if (!works) break;
                }
            }
            if (works) {
                System.out.println(k);
                break;
            }
        }
    }
}
