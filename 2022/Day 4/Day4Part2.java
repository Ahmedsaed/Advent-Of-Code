import java.io.*;

public class Day4Part2 {
    public static void main(String[] args) throws Exception {
        File file = new File("input.txt");

        BufferedReader bf = new BufferedReader(new FileReader(file));

        String st, part1, part2;
        int n11, n12, n21, n22, total = 0;

        while((st = bf.readLine()) != null) {
            part1 = st.split(",")[0];
            part2 = st.split(",")[1];

            n11 = Integer.parseInt(part1.split("-")[0]);
            n12 = Integer.parseInt(part1.split("-")[1]);
            n21 = Integer.parseInt(part2.split("-")[0]);
            n22 = Integer.parseInt(part2.split("-")[1]);

            
            if ((n11 <= n21 && n21 <= n12) || (n21 <= n11 && n11 <= n22)) {
                // System.out.printf(" %d - %d | %d - %d\n", n11, n12, n21, n22);
                total++;
            } 
        }

        System.out.println(total);

        bf.close();
    }
}
