import java.io.*;
import java.util.*;
public class timelimits {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()), s = Integer.parseInt(st.nextToken());

        int max = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(st.nextToken());
            if (num > max) max = num;
        }
        System.out.println((int)Math.ceil((max*s)/1000.0));
    }
}
