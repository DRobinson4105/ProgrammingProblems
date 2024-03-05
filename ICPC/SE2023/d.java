import java.util.*;

public class d {
    static class Pair {
        int first, second, length;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
            this.length = 0;
        }
    }
    private static List<Integer> findFactors(int n) {
        List<Integer> res = new ArrayList<>();

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                res.add(i);

                if (i * i != n) {
                    res.add(n / i);
                }
            }
        }
        
        res.add(n);
        Collections.sort(res);
        return res;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        boolean nonePrinted = true;

        int n = scan.nextInt();

        List<Integer> nums = new ArrayList<>();
        nums.add(0);

        for (int i = 1; i <= n; i++) {
            nums.add(scan.nextInt());
        }

        List<Integer> factors = findFactors(n);

        for (int k : factors) {
            int numSections = k;
            List<Pair> sections = new ArrayList<>();
            for (int i = 0; i <= numSections; i++) {
                sections.add(new Pair(Integer.MAX_VALUE, Integer.MIN_VALUE));
            }

            for (int i = 1; i <= n; i++) {
                int idx = (int)Math.round(Math.ceil(k * i / (double)n));
                Pair pair = sections.get(idx);
                pair.length++;
                pair.first = Math.min(pair.first, nums.get(i));
                pair.second = Math.max(pair.second, nums.get(i));
            }

            boolean flag = true;
            outer: for (int j = 1; j <= numSections; j++) {
                for (int i = 1; i < j; i++) {
                    if (sections.get(i).second > sections.get(j).first || sections.get(i).length != sections.get(j).length) {
                        flag = false;
                        break outer;
                    }
                }
            }


            if (flag) {
                System.out.println(k);
                nonePrinted = false;
            }
        }

        if (nonePrinted) System.out.println(-1);
        scan.close();
    }
}