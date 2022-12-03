/**
 * Day2Part2
 */

import java.io.*;


public class Day2Part2 {
    public static void main(String[] args) throws Exception {
        File file = new File("input.txt");
 
        BufferedReader br = new BufferedReader(new FileReader(file));
 
        String st;
        int totalScore = 0;

        while ((st = br.readLine()) != null) {
            char op = st.charAt(0), me = st.charAt(2);

            int win = 0;
            if (me == 'X') {
                if (op == 'A') win = 3;
                else if (op == 'B') win = 1;
                else win = 2;
            }
            else if (me == 'Y') {
                win = op - 'A' + 1;
            }
            else {
                if (op == 'A') win = 2;
                else if (op == 'B') win = 3;
                else win = 1;
            }

            totalScore += (me - 'X') * 3 + win;
        }

        System.out.println(totalScore);

        br.close();
    }
}