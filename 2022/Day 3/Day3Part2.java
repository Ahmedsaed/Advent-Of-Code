/**
 * Day3Part2
 */

import java.io.*;

public class Day3Part2 {
    public static void main(String[] args) throws Exception {
        File file = new File("input.txt");
 
        BufferedReader br = new BufferedReader(new FileReader(file));
 
        String first, second, third;
        int total = 0;

        while (true) {
            first = br.readLine();
            second = br.readLine();
            third = br.readLine();
            
            if (first == null || second == null || third == null) break;

            for (Character ch : first.toCharArray()) {
                if (second.indexOf(ch) != -1 && third.indexOf(ch) != -1) {
                    if (Character.isLowerCase(ch)) total += ch - 'a' + 1;
                    else total += ch - 'A' + 27;    

                    break;
                }
            }
        }

        System.out.println(total);

        br.close();
    }
}