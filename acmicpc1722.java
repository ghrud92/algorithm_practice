// 순열의 순서
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        long[] standard = new long[21];
        boolean[] check = new boolean[21];
        standard[0] = 1;
        for (int i = 1; i < 21; i++) {
            standard[i] = standard[i - 1] * i;
            check[i] = false;
        }

        String[] input = br.readLine().split(" ");
        int question = Integer.parseInt(input[0]);

        if (question == 1) {
            long order = Long.parseLong(input[1]);
            int[] result = new int[N];
            for (int i = 0; i < N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (check[j])
                        continue;
                    if (standard[N - i - 1] < order) {
                        order -= standard[N - i - 1];
                    } else {
                        result[i] = j;
                        check[j] = true;
                        break;
                    }
                }
            }
            bw.write(result[0] + "");
            for (int i = 1; i < N; i++)
                bw.write(" " + result[i]);
        } else {
            int[] permutation = new int[N];
            for (int i = 0; i < N; i++) {
                permutation[i] = Integer.parseInt(input[i + 1]);
            }

            long order = 0L;
            for (int i = 0; i < N; i++) {
                for (int j = 1; j < permutation[i]; j++) {
                    if (!check[j])
                        order += standard[N - i - 1];
                }
                check[permutation[i]] = true;
            }
            bw.write((order + 1) + "");
        }

        bw.write("\n");
        bw.flush();

        br.close();
        bw.close();
    }
}