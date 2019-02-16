// 퍼즐
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LinkedList<Integer> queue = new LinkedList<>();
        Map<Integer, Integer> map = new HashMap<>();
        final int END = 123456789;

        int start = 0;
        for (int i = 0; i < 9; i++) {
            int input = scanner.nextInt();
            start *= 10;
            start += (input == 0 ? 9 : input);
        }

        queue.addLast(start);
        map.put(start, 0);
        while (!queue.isEmpty()) {
            int current = queue.removeFirst();
            if (current == END)
                break;
            for (int i = 0; i < 4; i++) {
                int next = calculate(current, i);
                if (next != -1 && !map.containsKey(next)) {
                    queue.addLast(next);
                    map.put(next, map.get(current) + 1);
                }
            }
        }

        if (map.get(END) == null)
            System.out.println(-1);
        else
            System.out.println(map.get(END));
    }

    private static int calculate(int current, int direction) {
        int[] number = new int[9];
        int index = 0;
        for (int i = 0; i < 9; i++) {
            number[8 - i] = current % 10;
            if (number[8 - i] == 9)
                index = 8 - i;
            current /= 10;
        }

        // direction - 0 : up, 1 : right, 2 : down, 3 : left
        switch (direction) {
            case 0:
                if (index < 3)
                    return -1;
                number[index] = number[index - 3];
                number[index - 3] = 9;
                break;
            case 1:
                if (index % 3 == 2)
                    return -1;
                number[index] = number[index + 1];
                number[index + 1] = 9;
                break;
            case 2:
                if (index > 5)
                    return -1;
                number[index] = number[index + 3];
                number[index + 3] = 9;
                break;
            default:
                if (index % 3 == 0)
                    return -1;
                number[index] = number[index - 1];
                number[index - 1] = 9;
        }

        int result = 0;
        for (int i = 0; i < 9; i++) {
            result *= 10;
            result += number[i];
        }
        return result;
    }
}