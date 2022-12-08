import java.io.*;
import java.util.*;

public class Day7 {

    public static void main(String[] args) throws Exception {
        File file = new File("input.txt");

        BufferedReader bf = new BufferedReader(new FileReader(file));

        String st;
        Dictionary<String, Integer> dir = new Hashtable<String, Integer>();
        Vector<String> path = new Vector<String>();

        while ((st = bf.readLine()) != null) {
            String[] words = st.split(" ");
            if (words[1] == "cd") {
                if (words[2] == "..") path.remove(path.size()-1);
                else path.add(words[2]);
            } 
            else if (words[1] == "ls" || words[0] == "dir") continue;
            else {
                for (int i = 1; i < path.size()+1; i++) {
                    dir.put(String.join("/", path.subList(0, i)), Integer.parseInt(words[0]));
                }
            }
        }

        int p1 = 0, p2 = (int)1e9;

        for (Enumeration<String> i = dir.keys(); i.hasMoreElements();) {
            String s = i.nextElement();
            int size = dir.get(s);
            System.out.printf("%s -> %d", s, size);
            if (size <= 100000) {
                p1 += size;
            }
            if (size >= 1e9) {
                p2 = (p2 < size) ? p2 : size;  
            }
        }

        System.out.println(p1);
        System.out.println(p2);

        bf.close();
 
    }
}