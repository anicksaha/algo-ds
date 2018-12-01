import java.math.BigInteger;

import java.util.Scanner;

 
public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        while (in.hasNextInt()) 
       
         {

            int N = in.nextInt();

            int A = in.nextInt();

            BigInteger ans = BigInteger.ZERO;

            BigInteger sum = new BigInteger("0");

            BigInteger tmpA = BigInteger.valueOf(A);
            
            for(int i = 1; i <= N; i++)
            sum = sum.add(BigInteger.valueOf(i).multiply(tmpA.pow(i)));
            
            System.out.println(sum);
         }
    }
}
