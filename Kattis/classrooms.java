import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class classrooms {
    static class Pair implements Comparable<Pair> {
        int first;
        int second;
    
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    
        @Override
        public int compareTo(Pair other) {
            return this.first == other.first ? 
                (this.second - other.second) : 
                (this.first - other.first);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(stdin.readLine());
        List<Pair> activities = new ArrayList<Pair>();
        int total = 0;
        TreeSet<Pair> set = new TreeSet<Pair>();

        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(stdin.readLine());
            activities.add(new Pair(
                Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        // Sort activities in ascending order of their end times and then start times for
        // activities with the same end time
        Collections.sort(activities, (Pair a, Pair b) -> {
            return a.second == b.second ? (b.first - a.first) : (a.second - b.second);
        });

        // Start each classroom with an end time of 0
        for (int i = 0; i < k; i++)
            set.add(new Pair(0, i));

        // For each activity, find the classroom that starts the latest that will still end before
        // the current activity starts. If it exists, then the current activity can be scheduled
        // for that classroom and update the new end time of that classroom.
        for (Pair activity : activities) {
            Pair available = set.floor(new Pair(activity.first - 1, k));

            if (available != null) {
                total++;
                set.remove(available);
                set.add(new Pair(activity.second, available.second));
            }
        }

        System.out.println(total);
    }
}