// 다음 순열
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] permutaion = new int[N];
        for (int i = 0; i < N; i++) {
            permutaion[i] = Integer.parseInt(input[i]);
        }
        int lastBig = 0;
        for (int i = 1; i < N; i++) {
            if (permutaion[i] > permutaion[i - 1])
                lastBig = i;
        }
        if (lastBig == 0)
            bw.write("-1");
        else {
            int swap = lastBig;
            for (int i = lastBig + 1; i < N; i++) {
                if (permutaion[lastBig - 1] < permutaion[i]) {
                    swap = i;
                }
            }
            int temp = permutaion[lastBig - 1];
            permutaion[lastBig - 1] = permutaion[swap];
            permutaion[swap] = temp;
            for (int i = 0; i < (N - lastBig) / 2; i++) {
                temp = permutaion[lastBig + i];
                permutaion[lastBig + i] = permutaion[N - 1 - i];
                permutaion[N - 1 - i] = temp;
            }
            bw.write(permutaion[0] + "");
            for (int i = 1; i < N; i++)
                bw.write(" " + permutaion[i]);
        }

        bw.write("\n");
        bw.flush();

        br.close();
        bw.close();
    }
}