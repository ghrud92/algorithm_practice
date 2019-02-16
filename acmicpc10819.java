// 차이를 최대로
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    static int N;
    static int[] input;
    static boolean[] check;
    static int[] result;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        String[] temp = br.readLine().split(" ");
        input = new int[N];
        check = new boolean[N];
        result = new int[N];
        for (int i = 0; i < N; i++) {
            input[i] = Integer.parseInt(temp[i]);
            check[i] = false;
        }

        bw.write(calculate(0) + "\n");

//        bw.write("\n");
        bw.flush();

        br.close();
        bw.close();
    }

    private static int calculate(int index) {
        if (index == N) {
            // 합계 리턴
            int sum = 0;
            for (int i = 1; i < N; i++)
                sum += result[i - 1] > result[i] ? result[i - 1] - result[i] : result[i] - result[i - 1];
            return sum;
        }

        int max = 0;
        for (int i = 0; i < N; i++) {
            if (check[i])
                continue;

            check[i] = true;
            result[index] = input[i];
            int temp = calculate(index + 1);
            if (temp > max)
                max = temp;
            check[i] = false;
        }

        return max;
    }
}