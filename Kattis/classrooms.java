import java.util.*;

class Pair implements Comparable<Pair>{
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

public class classrooms {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        List<Integer[]> activities = new ArrayList<Integer[]>();
        int total = 0;
        TreeSet<Pair> set = new TreeSet<Pair>();

        // Get input
        int n = scan.nextInt(), k = scan.nextInt();
        for (int i = 0; i < n; i++)
            activities.add(new Integer[]{scan.nextInt(), scan.nextInt()});

        // Sort activities in ascending order of their end times and then start times for
        // activities with the same end time
        Collections.sort(activities, (Integer[] a, Integer[] b) -> {
            return a[1] == b[1] ? (b[0] - a[0]) : (a[1] - b[1]);
        });

        // Start each classroom with an end time of 0
        for (int i = 0; i < k; i++)
            set.add(new Pair(0, i));

        // For each activity, find the classroom that starts the latest that will still end before
        // the current activity starts. If it exists, then the current activity can be scheduled
        // for that classroom and update the new end time of that classroom.
        for (Integer[] activity : activities) {
            Pair available = set.floor(new Pair(activity[0] - 1, k));

            if (available != null) {
                total++;
                set.remove(available);
                set.add(new Pair(activity[1], available.second));
            }
        }

        System.out.println(total);
        scan.close();
    }
}
