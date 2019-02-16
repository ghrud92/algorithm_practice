// 외판원 순회 2
import java.util.Scanner;

public class Main {
    static final int INF = Integer.MAX_VALUE;
    static int N;
    static int[][] distance;
    static boolean[] check;
    static int[] route;

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);

        N = scanner.nextInt();
        distance = new int[N][N];
        check = new boolean[N];
        route = new int[N];
        for (int i = 0; i < N; i++) {
            check[i] = false;
            for (int j = 0; j < N; j++) {
                distance[i][j] = scanner.nextInt();
                if (i != j && distance[i][j] == 0) {
                    distance[i][j] = INF; // 길이 없는 경우
                }
            }
        }

        route[0] = 0;
        check[0] = true;
        System.out.println(travel(1));
    }

    private static int travel(int index) throws Exception {
        if (index == N) {
            int sum = 0;
            for (int i = 1; i < N; i++) {
                if (distance[route[i - 1]][route[i]] == INF)
                    return INF;
                sum += distance[route[i - 1]][route[i]];
            }
            if (distance[route[N - 1]][route[0]] == INF)
                return INF;
            sum += distance[route[N - 1]][route[0]];

            return sum;
        }

        int min = INF;
        for (int i = 1; i < N; i++) {
            if (check[i])
                continue;

            check[i] = true;
            route[index] = i;
            int temp = travel(index + 1);
            if (min > temp)
                min = temp;
            check[i] = false;
        }

        return min;
    }
}