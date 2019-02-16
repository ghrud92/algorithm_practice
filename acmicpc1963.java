// 소수 경로
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LinkedList<Integer> queue = new LinkedList<>();
        boolean[] prime = new boolean[10000];
        boolean[] check = new boolean[10000];
        int[] distance = new int[10000];
        for (int i = 0; i < 10000; i++) {
            prime[i] = true;
            check[i] = false;
        }
        for (int i = 2; i < 10000; i++) {
            if (prime[i]) {
                for (int j = 2; j < 5000; j++) {
                    if (i * j < 10000) {
                        prime[i * j] = false;
                    } else {
                        break;
                    }
                }
            }
        }

        int T = scanner.nextInt();
        for (int index = 0; index < T; index++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            queue.addLast(start);
            check[start] = true;
            distance[start] = 0;
            while (!queue.isEmpty()) {
                int current = queue.removeFirst();
                if (current == end)
                    break;
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 10; j++) {
                        if (i == 0 && j == 0)
                            continue;
                        int modified = getModified(current, i, j);
                        if (prime[modified] && !check[modified]) {
                            queue.addLast(modified);
                            check[modified] = true;
                            distance[modified] = distance[current] + 1;
                        }
                    }
                }
            }
            System.out.println(distance[end]);
            queue.clear();
            for (int i = 0; i < 10000; i++) {
                check[i] = false;
                distance[i] = 0;
            }
        }
    }

    private static int getModified(int num, int i, int j) {
        int[] number = new int[4];
        for (int index = 0; index < 4; index++) {
            number[3 - index] = num % 10;
            num /= 10;
        }
        number[i] = j;
        int result = 0;
        for (int index = 0; index < 4; index++) {
            result *= 10;
            result += number[index];
        }
        return result;
    }
}