import java.util.*;
import java.math.*;

public class Krakovia {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int turn = 1;
        while (true) {
            int n = sc.nextInt();
            int f = sc.nextInt();
            if (n == 0 && f == 0)
                break;
            BigInteger sum = BigInteger.valueOf(0);

            for (int i = 0; i < n; i++) {
                BigInteger tem = sc.nextBigInteger();
                sum = sum.add(tem);
            }

            BigInteger av = sum.divide(BigInteger.valueOf(f));
            System.out.println("Bill #" + turn + " costs " + sum + ": each friend should pay " + av);
            System.out.println();
            turn++;
        }
        sc.close();
    }

}
