/**
 * Day1
 */

import java.io.*;

public class Day1 {

    public static void main(String[] args) throws Exception {
        File file = new File("/home/ahmed/Documents/Projects/Problem Solving/Advent-Of-Code/2022/Day 1/input.txt");
 
        BufferedReader br = new BufferedReader(new FileReader(file));
 
        String st;
        int current = 0;
        int[] top = new int[3]; // change the size to 1 to get the answer of part 1

        while (true) {
            st = br.readLine();
            if (st == null || st.isEmpty()) {
                int mini = top.length - 1;
                for (int i = 0; i < top.length; i++) {
                    if (top[i] < top[mini]) mini = i;
                }

                if (current > top[mini]) top[mini] = current;

                current = 0;

                if (st == null) break;
            }
            else {
                current += Integer.parseInt(st);
            }
        }
        
        System.out.println(arraySum(top));

        br.close();
    }

    public static int arraySum(int[] array) {
        int sum = 0;
        for (int value : array) {
            sum += value;
        }
        return sum;
    }    
}