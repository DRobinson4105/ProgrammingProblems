import java.util.*;
import java.io.*;
public class socks {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return b-a;
            }
        });
        for (int i = 0; i < n; i++) pq.add(Integer.parseInt(br.readLine()));

        long res = 0;
        while (!pq.isEmpty()) {
            int socksColor1 = pq.poll();
            if (pq.isEmpty()) break;
            int socksColor2 = pq.poll();

            int take = (int)Math.ceil(Math.min(socksColor1, socksColor2)/2.0);
            res += take;
            socksColor1 -= take;
            socksColor2 -= take;
            if (socksColor1 != 0) pq.add(socksColor1);
            if (socksColor2 != 0) pq.add(socksColor2);
        }
        System.out.println(res);
        
    }
}
