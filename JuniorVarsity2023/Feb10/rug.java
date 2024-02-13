import java.util.*;
import java.io.*;
public class rug {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int rootN = Integer.parseInt(st.nextToken()), rootS = Integer.parseInt(st.nextToken());
        int[][] prefix2d = new int[rootN+1][rootN+1];
        for (int i = 1; i <= rootN; i++) {
            char[] floor = br.readLine().toCharArray();
            for (int j = 0; j < floor.length; j++) prefix2d[i][j+1] = floor[j] == 'D' ? 1 : 0;
        }

        for (int i = 1; i < prefix2d.length; i++) for (int j = 1; j < prefix2d.length; j++) prefix2d[i][j] += prefix2d[i][j-1];
        for (int i = 1; i < prefix2d.length; i++) for (int j = 1; j < prefix2d.length; j++) prefix2d[i][j] += prefix2d[i-1][j];

        int[] map = new int[rootN*rootN+1];
        Arrays.fill(map, 0);

        for (int i = rootS; i <= rootN; i++) for (int j = rootS; j <= rootN; j++) map[prefix2d[i][j]-prefix2d[i-rootS][j]-prefix2d[i][j-rootS]+prefix2d[i-rootS][j-rootS]]++; 
        for (int i = 0; i < map.length; i++) if (map[i] != 0) System.out.println(i+" "+map[i]);
    }
}
