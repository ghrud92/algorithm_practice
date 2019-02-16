// 1, 2, 3 더하기
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        int[] value = new int[11];
        value[1] = 1;
        value[2] = 2;
        value[3] = 4;
        for (int i = 4; i < 11; i++)
            value[i] = value[i - 1] + value[i - 2] + value[i -3];

        for (int i = 0; i < T; i++) {
            int num = Integer.parseInt(br.readLine());
            bw.write(value[num] + "\n");
        }

//        bw.write("\n");
        bw.flush();

        br.close();
        bw.close();
    }
}