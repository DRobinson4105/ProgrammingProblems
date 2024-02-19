import java.io.*;
import java.util.*;
public class d {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
        int res = 0;
        while (a > b) {
            if (a % 2 == 0) a /= 2;
            else a += 1;
            res++;
        }
        res += (b-a);
        System.out.println(res);
    }
}
