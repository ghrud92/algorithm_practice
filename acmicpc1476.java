// 날짜 계산
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int[] target = new int[3];
        for (int i = 0; i < 3; i++) {
            target[i] = Integer.parseInt(input[i]);
        }
        final int limitE = 16;
        final int limitS = 29;
        final int limitM = 20;

        int year = 1;
        int E = 1, S = 1, M = 1;
        while (true) {
            if (E == target[0] && S == target[1] && M == target[2])
                break;
            E++;
            S++;
            M++;
            E = E < limitE ? E : 1;
            S = S < limitS ? S : 1;
            M = M < limitM ? M : 1;
            year++;
        }
        bw.write(year + "");

        bw.write("\n");
        bw.flush();

        br.close();
        bw.close();
    }
}