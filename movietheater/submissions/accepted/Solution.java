import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.TreeSet;

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

    static int closestDistance(TreeSet<Integer> setik, int val) {
        int res = 1_000_000_000;
        Integer f = setik.floor(val);
        if (f != null) {
            res = Math.min(res, val - f);
        }
        Integer c = setik.ceiling(val);
        if (c != null) {
            res = Math.min(res, c - val);
        }
        return res;
    }

    static void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        TreeSet<Integer> topE = new TreeSet<>();
        TreeSet<Integer> botE = new TreeSet<>();
        TreeSet<Integer> leftE = new TreeSet<>();
        TreeSet<Integer> rightE = new TreeSet<>();
        TreeSet<Integer> topX = new TreeSet<>();
        TreeSet<Integer> botX = new TreeSet<>();
        TreeSet<Integer> leftX = new TreeSet<>();
        TreeSet<Integer> rightX = new TreeSet<>();

        List<Point> points = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String s = nextToken();
            for (int j = 0; j < m; j++) {
                char c = s.charAt(j);
                if (c == 'E') {
                    if (i == 0) {
                        topE.add(j);
                    }
                    if (i == n - 1) {
                        botE.add(j);
                    }
                    if (j == 0) {
                        leftE.add(i);
                    }
                    if (j == m - 1) {
                        rightE.add(i);
                    }
                } else if (c == 'X') {
                    if (i == 0) {
                        topX.add(j);
                    }
                    if (i == n - 1) {
                        botX.add(j);
                    }
                    if (j == 0) {
                        leftX.add(i);
                    }
                    if (j == m - 1) {
                        rightX.add(i);
                    }
                } else if (c == 'S') {
                    points.add(new Point(i, j));
                }
            }
        }

        int ans = 1_000_000_000;
        for (Point p : points) {
            int closestE = 1_000_000_000;
            closestE = Math.min(closestE, p.x + closestDistance(topE, p.y));
            closestE = Math.min(closestE, n - 1 - p.x + closestDistance(botE, p.y));
            closestE = Math.min(closestE, p.y + closestDistance(leftE, p.x));
            closestE = Math.min(closestE, m - 1 - p.y + closestDistance(rightE, p.x));

            int closestX = 1_000_000_000;
            closestX = Math.min(closestX, p.x + closestDistance(topX, p.y));
            closestX = Math.min(closestX, n - 1 - p.x + closestDistance(botX, p.y));
            closestX = Math.min(closestX, p.y + closestDistance(leftX, p.x));
            closestX = Math.min(closestX, m - 1 - p.y + closestDistance(rightX, p.x));

            ans = Math.min(ans, closestE + closestX);
        }
        writer.print(ans);
    }

    static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}