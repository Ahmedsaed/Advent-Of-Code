/**
 * Day2Part1
 */

import java.io.*;


public class Day2Part1 {

    public static void main(String[] args) throws Exception {
        File file = new File("input.txt");
 
        BufferedReader br = new BufferedReader(new FileReader(file));
 
        String st;
        int totalScore = 0;

        while ((st = br.readLine()) != null) {
            char op = st.charAt(0), me = st.charAt(2);

            int win = 0;
            if (op - 'A' == me - 'X') {win = 3;}
            else if (op == 'A' && me == 'Y') {win = 6;}
            else if (op == 'A' && me == 'Z') {win = 0;}
            else if (op == 'B' && me == 'X') {win = 0;}
            else if (op == 'B' && me == 'Z') {win = 6;}
            else if (op == 'C' && me == 'X') {win = 6;}
            else if (op == 'C' && me == 'Y') {win = 0;}

            totalScore += (me - 'X' + 1) + win;
        }

        System.out.println(totalScore);

        br.close();
    }
}