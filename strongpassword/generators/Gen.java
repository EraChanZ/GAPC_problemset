import java.util.Random;

public class Gen {

    static char nextChar(Random rnd, String rule) {
        char type = rule.charAt(rnd.nextInt(rule.length()));
        if (type == 'U') {
            return (char) ('A' + rnd.nextInt(26));
        } else if (type == 'L') {
            return (char) ('a' + rnd.nextInt(26));
        } else if (type == 'D') {
            return (char) ('0' + rnd.nextInt(10));
        } else {
            throw new IllegalStateException();
        }
    }

    public static void main(String[] args) {
        if (args.length < 3) {
            throw new IllegalArgumentException("Usage: java Gen SEED RULE LENGTH");
        }
        long seed = Long.parseLong(args[0]);
        String rule = args[1];
        int length = Integer.parseInt(args[2]);
        Random rnd = new Random(seed);
        for (int i = 0; i < length; i++) {
            System.out.print(nextChar(rnd, rule));
        }
        System.out.println();
    }
}
