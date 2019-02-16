// 로또
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            String[] input = br.readLine().split(" ");
            int k = Integer.parseInt(input[0]);
            if (k == 0)
                break;

            int[] flags = new int[k];
            int[] permutation = new int[k];
            for (int i = 0; i < k; i++) {
                flags[i] = 1;
                permutation[i] = Integer.parseInt(input[i + 1]);
            }
            for (int i = 0; i < 6; i++) {
                flags[i] = 0;
            }

            do {
                for (int i = 0; i < k; i++) {
                    if (flags[i] == 0) {
                        bw.write(permutation[i] + " ");
                    }
                }
                bw.write("\n");
            } while (next_flags(flags));
            bw.write("\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }

    private static boolean next_flags(int[] flags) {
        int grow = 0;
        for (int i = 1; i < flags.length; i++) {
            if (flags[i] > flags[i - 1])
                grow = i;
        }
        if (grow == 0)
            return false;

        flags[grow - 1] = 1;
        flags[grow] = 0;
        int count = 0;
        for (int i = grow + 1; i < flags.length; i++) {
            if (flags[i] == 1)
                count++;
            flags[i] = 0;
        }
        for (int i = 0; i < count; i++) {
            flags[flags.length - 1 - i] = 1;
        }

        return true;
    }
}