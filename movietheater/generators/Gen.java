import java.util.Random;
import java.util.StringTokenizer;

public class Gen {

    static int getDimension(Random rnd, String param) {
        if (param.contains("..")) {
            StringTokenizer tokenizer = new StringTokenizer(param, ".");
            int from = Integer.parseInt(tokenizer.nextToken());
            int to = Integer.parseInt(tokenizer.nextToken());
            if (from > to) {
                throw new IllegalArgumentException("Can't generate dimension between " + from + " and " + to);
            }
            return from + rnd.nextInt(to - from + 1);
        } else {
            return Integer.parseInt(param);
        }
    }

    public static void main(String[] args) {
        if (args.length < 6) {
            throw new IllegalArgumentException("Usage: java Gen SEED N M EPROB XPROB SPROB");
        }
        long seed = Long.parseLong(args[0]);
        Random rnd = new Random(seed);
        int n = getDimension(rnd, args[1]);
        int m = getDimension(rnd, args[2]);
        double eprob = Double.parseDouble(args[3]);
        double xprob = Double.parseDouble(args[4]);
        double sprob = Double.parseDouble(args[5]);
        char[][] grid = new char[n][m];
        int attempts = 0;
        while (true) {
            attempts++;
            if (attempts > 10) {
                throw new IllegalArgumentException("Can't generate a valid grid after 10 attempts");
            }
            boolean haveE = false;
            boolean haveX = false;
            boolean haveS = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    boolean isEdge = i == 0 || i == n - 1 || j == 0 || j == m - 1;
                    double p = rnd.nextDouble();
                    if (isEdge) {
                        if (p < eprob) {
                            grid[i][j] = 'E';
                            haveE = true;
                        } else if (p < eprob + xprob) {
                            grid[i][j] = 'X';
                            haveX = true;
                        } else {
                            grid[i][j] = '.';
                        }
                    } else {
                        if (p < sprob) {
                            grid[i][j] = 'S';
                            haveS = true;
                        } else {
                            grid[i][j] = '.';
                        }
                    }
                }
            }
            if (haveE && haveX && haveS) {
                break;
            }
        }
        System.out.println(n + " " + m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }
    }
}
