import java.util.*;
import java.io.*;

public class breakingbad {
    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        Set<String> first = new HashSet<>(), second = new HashSet<>();
        LinkedList<String> queue = new LinkedList<>();

        // for linking words that can't be bought together
        Map<String, Set<String>> map = new HashMap<>();

        // items
        int n = Integer.parseInt(stdin.readLine());
        for (int i = 0; i < n; i++)
            map.put(stdin.readLine(), new HashSet<>());

        // pairs
        int m = Integer.parseInt(stdin.readLine());
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(stdin.readLine());
            String str1 = st.nextToken(), str2 = st.nextToken();

            map.get(str1).add(str2);
            map.get(str2).add(str1);
        }


        for (String item : map.keySet()) {
            // item has already been added to a set
            if (first.contains(item) || second.contains(item)) continue;
            queue.add(item);
            first.add(item);

            while (!queue.isEmpty()) {
                String curr = queue.poll();
    
                // items that cannot be with curr
                for (String next : map.get(curr)) {
                    // if next is in the same set as curr, then there is no solution
                    if (first.contains(curr) && first.contains(next) || 
                            second.contains(curr) && second.contains(next)) {
                        System.out.println("impossible");
                        return;
                    }
    
                    // if curr is in first set and next has not been added to second set
                    if (first.contains(curr) && !second.contains(next)) {
                        second.add(next);
                        queue.add(next);
                    }
                    
                    // if curr is in second set and next has not been added to first set
                    else if (second.contains(curr) && !first.contains(next)) {
                        first.add(next);
                        queue.add(next);
                    }
                }
            }
        }

        // print both sets
        for (String item : first) {
            sb.append(item); sb.append(" ");
        }
        System.out.println(sb);

        sb = new StringBuilder();

        for (String item : second) {
            sb.append(item); sb.append(" ");
        }
        System.out.println(sb);
    }
}
