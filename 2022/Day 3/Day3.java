/**
 * Day3
 */

import java.io.*;

public class Day3 {
    public static void main(String[] args) throws Exception {
        File file = new File("input.txt");
 
        BufferedReader br = new BufferedReader(new FileReader(file));
 
        String st;
        int total = 0;

        while ((st = br.readLine()) != null) {
            String first = st.substring(0, st.length()/2), second = st.substring(st.length()/2);

            for (char ch : first.toCharArray()) {
                if (second.indexOf(ch) != -1) {
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