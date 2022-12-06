import java.io.*;

public class Day6Part2 {

    public static void main(String[] args) throws Exception {
        File file = new File("input.txt");

        BufferedReader bf = new BufferedReader(new FileReader(file));

        String st = bf.readLine();
        boolean flag = false;

        for (int i = 0; i < st.length() - 14; i++) {
            String substr = st.substring(i, i+14);
            for (int j = 0; j < substr.length(); j++) {
                if (substr.indexOf(substr.charAt(j)) != -1 && substr.indexOf(substr.charAt(j)) != j) {
                    flag = true;
                }
            }
            if (!flag) {
                System.out.println(i+14);
                break;
            }
            flag = false;
        }

        bf.close();
    }
}