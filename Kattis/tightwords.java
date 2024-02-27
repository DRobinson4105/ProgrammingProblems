import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import static java.lang.Math.*;

public class tightwords {
    private static int k, n;
    private static double[][] dp;
    
    private static double solve(int curr, int last) {
        // if new solution is found
        if (curr == n) return 1;

        // if we have already went down this path
        if (last != k + 1 && dp[curr][last] != -1) return dp[curr][last];

        double total = 0;

        // for each possible next value
        for (int i = 0; i <= k; i++) {
            if (last != k + 1 && abs(i - last) > 1) continue;
            total += solve(curr + 1, i);
        }

        // return and save value for this path
        return dp[curr][last] = total / (k + 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String line;

        while ((line = stdin.readLine()) != null) {
            st = new StringTokenizer(line);
            k = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            dp = new double[n][k + 2];
            for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++) dp[i][j] = -1;

            // use k + 1 as last since it is the next value that won't be used
            System.out.println(solve(0, k + 1) * 100);
        }
    }
}