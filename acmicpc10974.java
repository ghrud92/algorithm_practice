// 모든 순열
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        boolean[] check = new boolean[N];
        for (int i = 0; i < N; i++)
            check[i] = false;

        recursive(check, new LinkedList<>(), bw);

//        bw.write("\n");
        bw.flush();

        br.close();
        bw.close();
    }

    private static void recursive(boolean[] check, LinkedList<Integer> resultList, BufferedWriter bw) throws Exception {
        boolean isEnd = true;
        for (int i = 0; i < check.length; i++) {
            if (check[i])
                continue;

            isEnd = false;
            check[i] = true;
            resultList.addLast(i + 1);
            recursive(check, resultList, bw);
            check[i] = false;
            resultList.removeLast();
        }
        if (isEnd) {
            bw.write(resultList.get(0) + "");
            for (int i = 1; i < resultList.size(); i++)
                bw.write(" " + resultList.get(i));
            bw.write("\n");
        }
    }
}