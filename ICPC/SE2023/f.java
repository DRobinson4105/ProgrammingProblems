import java.util.*;
import java.io.*;

public class f {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] dice = new int[7];
        int[] diceRolls = new int[n];
        for (int i = 0; i < n; i++) dice[diceRolls[i] = Integer.parseInt(st.nextToken())]++;

        int different = 0;
        boolean sameFound = false;
        for (int i = 0; i < dice.length; i++) {
            if (dice[i] > 1) sameFound = true;
            if (dice[i] == 1) different++;
        }
        
        if (sameFound) {
            System.out.println(0+" " +(int)Math.pow(6, 4-n));
        } else {
            int resAsh = 1;
            int resBrand = 0;

            int counter = 4-n-1;
            for (int i = 0; i < 4-n; i++) resAsh *= (6-different-i);
            for (int i = 0; i < 4-n; i++) {
                int temp = 1;
                for (int j = 0; j < 4-n; j++) {
                    if (j < counter) temp *= (6-different-j);
                    else if (j == counter) temp *= different+j;
                    else temp *= 6; 
                }
                resBrand += temp;
                counter--;
            }
            System.out.println(resAsh + " " + resBrand);
        }

    }
}