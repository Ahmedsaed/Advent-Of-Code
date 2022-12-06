/**
 * Day5Part1
 */

import java.io.*;
import java.util.Collections;
import java.util.Stack;

public class Day5Part1 {

    public static void main(String[] args) throws Exception {
        File file = new File("input.txt");

        BufferedReader bf = new BufferedReader(new FileReader(file));

        final int N = 9;
        String st;
        Stack<Character>[] stk = new Stack[N];

        for (int i = 0; i < N; ++i)
            stk[i] = new Stack();

        for (int i = 0; i < 8; i++) {
            st = bf.readLine();

            for (int j = 0; j < st.length(); j++) {
                Character ch = st.charAt(j);
                if (ch != ' ' && ch != '[' && ch != ']' && ch != null) {
                    stk[(j - 1) / 4].push(ch);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            stk[i] = reverse(stk[i]);
        }

        while ((st = bf.readLine()) != null) {
            if (st.indexOf("move") != -1) {
                String[] ops = st.split(" ");
                int n = Integer.parseInt(ops[1]), from = Integer.parseInt(ops[3]) - 1, to = Integer.parseInt(ops[5]) - 1;
                for (int i = 0; i < n; i++) {
                    Character ch = stk[from].pop();
                    stk[to].push(ch);
                }
            }
        }
        
        for (Stack<Character> stack : stk) {
            System.out.print(stack.peek());
        }
        System.out.println();
        
        bf.close();
    }

    public static Stack<Character> reverse(Stack<Character> stk){
        Stack<Character> extraStack = new Stack<Character>();
        int n = stk.size();
     
        for (int i = 0; i < n; i++) {
          Character element = stk.peek();
          stk.pop();
          extraStack.push(element);
        }
     
        return extraStack;
    }
}