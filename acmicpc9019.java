// DSLR
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LinkedList<Integer> queue = new LinkedList<>();
        boolean[] check = new boolean[10000];
        String[] result = new String[10000];

        int T = scanner.nextInt();
        for (int test = 0; test < T; test++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            queue.addLast(start);
            check[start] = true;
            result[start] = "";
            while (!queue.isEmpty()) {
                int current = queue.removeFirst();
                if (current == end)
                    break;

                for (int i = 0; i < 4; i++) {
                    int next = calculate(current, i);
                    if (!check[next]) {
                        queue.addLast(next);
                        check[next] = true;
                        result[next] = result[current] + getString(i);
                    }
                }
            }
            System.out.println(result[end]);
            queue.clear();
            for (int i = 0; i < 10000; i++) {
                check[i] = false;
                result[i] = null;
            }
        }
    }

    private static int calculate(int num, int i) {
        switch (i) {
            case 0:
                return (num * 2) % 10000;
            case 1:
                return num == 0 ? 9999 : num - 1;
            case 2:
                return (num % 1000) * 10 + num / 1000;
            default:
                return (num % 10) * 1000 + (num / 10);
        }
    }

    private static String getString(int i) {
        switch (i) {
            case 0:
                return "D";
            case 1:
                return "S";
            case 2:
                return "L";
            default:
                return "R";
        }
    }
}