// 비트마스크
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        int S = 0;
        for (int count = 0; count < N; count++) {
            String order = br.readLine();
            if ("all".equals(order)) {
                S = (1 << 21) - 1;
            } else if ("empty".equals(order)) {
                S = 0;
            } else {
                String[] data = order.split(" ");
                int num = Integer.parseInt(data[1]);
                if ("add".equals(data[0])) {
                    S = S | (1 << num);
                } else if ("remove".equals(data[0])) {
                    S = S & ~(1 << num);
                } else if ("check".equals(data[0])) {
                    if ((S & (1 << num)) != 0)
                        bw.write("1\n");
                    else
                        bw.write("0\n");
                } else if ("toggle".equals(data[0])) {
                    S = S ^ (1 << num);
                }
            }
        }
        bw.flush();
        br.close();
        bw.close();
    }
}