import java.nio.file.Files;
import java.nio.file.Path;

public class Day8 {

    public static void main(String[] args) throws Exception {
        String st = Files.readString(Path.of("/home/ahmed/Documents/Projects/Problem Solving/Advent-Of-Code/2022/Day 8/input.txt"));
        String[] lines = st.split("\n");
        int f_height = lines.length, f_width = lines[0].length();
        
        int vis_tree = 2 * f_height + 2 * f_width - 4, best_score = 0;
        for (int i = 1; i < f_height-1; i++) {
            for (int j = 1; j < f_width-1; j++) {
                boolean vis = true;
                int tree_height = lines[i].charAt(j), score = 1, count = 0, inc = 0;

                // Up
                for (int k = i-1; k >= 0; k--) {
                    count++;
                    if (tree_height <= lines[k].charAt(j)) {
                        vis = false;
                        break;
                    }
                }
                if (vis) inc = 1;
                score *= count;

                //Down
                vis = true;
                count = 0;
                for (int k = i+1; k < f_height; k++) {
                    count++;
                    if (tree_height <= lines[k].charAt(j)) {
                        vis = false;
                        break;
                    }
                }
                if (vis) inc = 1;
                score *= count;

                //Left
                vis = true;
                count = 0;
                for (int k = j-1; k >= 0; k--) {
                    count++;
                    if (tree_height <= lines[i].charAt(k)) {
                        vis = false;
                        break;    
                    }
                }
                if (vis) inc = 1;
                score *= count;

                //Right
                vis = true;
                count = 0;
                for (int k = j+1; k < f_width; k++) {
                    count++;
                    if (tree_height <= lines[i].charAt(k)) {
                        vis = false;
                        break;    
                    }
                }
                if (vis) inc = 1;
                score *= count;
                
                vis_tree += inc; 
                best_score = (score > best_score) ? score : best_score;
            }
        }

        System.out.println(vis_tree);
        System.out.println(best_score);
    }
}