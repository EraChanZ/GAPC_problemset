import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class NoIncrement {
    static BufferedReader reader;
    static StringTokenizer tokenizer;
    static PrintWriter writer;

    static String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public static void main(String[] args) throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
        writer = new PrintWriter(System.out);
        solve();
        reader.close();
        writer.close();
    }

    private static boolean can(List<Integer> a, List<Integer> b, int k, int dist) {
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        int got = 0;
        int last = -1_000_000_000;
        while (true) {
            if (got % 2 == 0) {
                while (i < n && a.get(i) - last < dist) {
                    i++;
                }
                if (i == n) {
                    return false;
                }
                last = a.get(i);
                got++;
                if (got == 2 * k - 1) {
                    return true;
                }
            } else {
                while (j < m && b.get(j) - last < dist) {
                    j++;
                }
                if (j == m) {
                    return false;
                }
                last = b.get(j);
                got++;
            }
        }
    }

    static void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(nextInt());
        }
        List<Integer> b = new ArrayList<>();
        for (int j = 0; j < m; j++) {
            b.add(nextInt());
        }
        int l = 0;
        int r = 1_000_000_000;
        while (l + 1 != r) {
            int mid = (l + r) / 2;
            if (can(a, b, k, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (can(a, b, k, l)) {
            writer.println(l);
        } else {
            writer.println(-1);
        }
    }
}