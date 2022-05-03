import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution {
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

    static void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        double[] ans = new double[n];
        double win = 1.0 / m;
        double lose = (m - 1.0) / m;
        for (int k = 0; k < 1_000_000; k++) {
            ans[k % n] += Math.pow(lose, k) * win;
        }
        for (int i = 0; i < n; i++) {
            writer.print(ans[i] + " ");
        }
    }
}