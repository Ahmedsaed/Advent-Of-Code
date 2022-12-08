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

            if (words[1].equals("cd")) {
                if (words[2].equals("..")) path.remove(path.size()-1);
                else path.add(words[2]);
            } 
            else if (words[1].equals("ls") || words[0].equals("dir")) continue;
            else {
                for (int i = 1; i < path.size()+1; i++) {
                    String s = String.join("/", path.subList(0, i));
                    if (dir.get(s) == null) dir.put(s, 0);
                    dir.put(s, dir.get(s)+Integer.parseInt(words[0]));
                }
            }
        }
        int p1 = 0;
        long p2 = (long)1e9;
        long r = 30000000 - (70000000 - dir.get("/"));

        for (Enumeration<String> i = dir.keys(); i.hasMoreElements();) {
            String s = i.nextElement();
            int size = dir.get(s);

            if (size <= 100000) {
                p1 += size;
            }
            if (size >= r) {
                p2 = (p2 < size) ? p2 : size;  
            }
        }

        System.out.println(p1);
        System.out.println(p2);

        bf.close();
 
    }
}