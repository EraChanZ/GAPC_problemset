import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class NonAbsolute {
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
        int w = nextInt();
        int h = nextInt();
        int n = nextInt();
        double angle = Math.toRadians(n);
        double ans = (w * w + h * h) * Math.cos(angle) * Math.sin(angle);
        writer.println(ans);
    }
}