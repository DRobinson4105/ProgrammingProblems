import java.util.*;
import java.io.*;
public class truth {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[][] range = new int[n][2];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            range[i][0] = Integer.parseInt(st.nextToken());
            range[i][1] = Integer.parseInt(st.nextToken());
        }

        boolean truthFound = false;
        for (int i = n; i >= 0; i--) {
            int truthTellers = 0;
            for (int j = 0; j < n; j++) {
                if (i >= range[j][0] && i <= range[j][1]) {
                    truthTellers++;
                    if (truthTellers > i) break;
                }
            }
            if (truthTellers == i) {
                System.out.println(i);
                truthFound = true;
                break;
            }
        }
        if (!truthFound) System.out.println(-1);
    }
}
