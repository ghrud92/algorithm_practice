// 리모컨
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    private static int target;
    private static int current;
    private static boolean[] available;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        current = 100;
        available = new boolean[10];
        for (int i = 0; i < 10; i++)
            available[i] = true;
        target = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
        if (k > 0) {
            String[] input = br.readLine().split(" ");
            for (int i = 0; i < k; i++)
                available[Integer.parseInt(input[i])] = false;
        }

        int min = target - 100;
        min = min > 0 ? min : (min * -1);

        for (int i = 0; i < 1000000; i++) {
            if (possible(i)) {
                int temp = target - i;
                temp = temp > 0 ? temp : (temp * -1);
                temp += digit(i);
                if (min > temp)
                    min = temp;
            }
        }
        bw.write(min + "");

        bw.write("\n");
        bw.flush();

        br.close();
        bw.close();
    }

    private static boolean possible(int num) {
        if (num == 0) {
            if (available[0])
                return true;
            else
                return false;
        }
        while (num > 0) {
            if (!available[num % 10])
                return false;
            num /= 10;
        }
        return true;
    }

    private static int digit(int num) {
        int count = 1;
        while (num > 9) {
            count++;
            num /= 10;
        }
        return count;
    }
}