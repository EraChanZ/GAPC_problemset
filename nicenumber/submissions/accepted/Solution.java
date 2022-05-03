import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
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

    static boolean test(String s) {
        if (s.charAt(0) == '0') {
            return false;
        }
        BigInteger bi = new BigInteger(s);
        if (bi.isProbablePrime(30)) {
            return true;
        }
        for (int i = 1; i < s.length(); i++) {
            String prefix = s.substring(0, i);
            if (new BigInteger(prefix).isProbablePrime(30)) {
                String rest = s.substring(i);
                if (test(rest)) {
                    return true;
                }
            }
        }
        return false;
    }

    static void solve() throws IOException {
        String s = nextToken();
        if (test(s)) {
            writer.println("YES");
        } else {
            writer.println("NO");
        }
    }
}