// 순열의 순서
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        long[] standard = new long[N - 1];
        if (N != 1) {
            standard[N - 2] = 1;
            for (int i = 1; i < N - 1; i++) {
                standard[N - 2 - i] = standard[N - 1 - i] * (i + 1);
            }
        }
        String[] input = br.readLine().split(" ");
        int question = Integer.parseInt(input[0]);

        if (N == 1) {
            bw.write("1");
        } else if (question == 1) {
            long order = Long.parseLong(input[1]) - 1;
            if (N == 2) {
                if (order == 0)
                    bw.write("1 2");
                else
                    bw.write("2 1");
            } else {
                LinkedList<Integer> startList = new LinkedList<>();
                for (int i = 0; i < N; i++)
                    startList.add(i + 1);
                LinkedList<Integer> resultList = new LinkedList<>();
                getPermutation(standard, order, resultList, startList);

                bw.write(resultList.get(0) + "");
                for (int i = 1; i < resultList.size(); i++)
                    bw.write(" " + resultList.get(i));
            }
        } else {
            LinkedList<Integer> permutaion = new LinkedList<>();
            boolean[] check = new boolean[N];
            for (int i = 0; i < N; i++) {
                permutaion.add(Integer.parseInt(input[i + 1]));
                check[i] = false;
            }
            long order = getOrder(standard, check, permutaion) + 1;
            bw.write(order + "");
        }

        bw.write("\n");
        bw.flush();

        br.close();
        bw.close();
    }

    private static void getPermutation(long[] standard, long order, LinkedList resultList, LinkedList startList) {
        int currentIndex = resultList.size();
        if (currentIndex == standard.length) {
            resultList.add(startList.getFirst());
            startList.removeFirst();
            return;
        }
        int num = (int) (order / standard[currentIndex]);
        resultList.add(startList.get(num));
        startList.remove(num);
        getPermutation(standard, order % standard[currentIndex], resultList, startList);
    }

    private static long getOrder(long[] standard, boolean[] check, LinkedList<Integer> permutation) {
        if (permutation.size() == 1) {
            return 0L;
        }

        int currentIndex = check.length - permutation.size();
        int count = 0;
        int permuNum = permutation.getFirst();
        check[permuNum - 1] = true;
        permutation.removeFirst();
        for (int i = 0; i < permuNum - 1; i++) {
            if (check[i])
                continue;
            count++;
        }

        return standard[currentIndex] * count + getOrder(standard, check, permutation);
    }
}