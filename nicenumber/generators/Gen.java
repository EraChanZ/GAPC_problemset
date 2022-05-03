import java.math.BigInteger;
import java.util.Random;
import java.util.TreeSet;

public class Gen {
    private static int generatePrime(Random rnd, int len) {
        while (true) {
            int res = 1 + rnd.nextInt(9);
            for (int i = 1; i < len; i++) {
                res *= 10;
                res += rnd.nextInt(10);
            }
            if (new BigInteger(res + "").isProbablePrime(30)) {
                return res;
            }
        }
    }

    public static void main(String[] args) {
        if (args.length < 3) {
            throw new IllegalArgumentException("Usage: Gen.java SEED LENGTH PRIME_COUNT");
        }
        long seed = Long.parseLong(args[0]);
        Random rnd = new Random(seed);
        int length = Integer.parseInt(args[1]);
        int primes = Integer.parseInt(args[2]);
        if (length < primes) {
            throw new IllegalArgumentException("LENGTH < PRIME_COUNT");
        }
        TreeSet<Integer> pivots = new TreeSet<>();
        while (pivots.size() < primes - 1) {
            int pivot = rnd.nextInt(length - 1);
            pivots.add(pivot);
        }
        pivots.add(length - 1);
        int from = 0;
        for (int pivot : pivots) {
            int len = pivot - from + 1;
            System.out.print(generatePrime(rnd, len));
            from = pivot + 1;
        }
        System.out.println();
    }
}
