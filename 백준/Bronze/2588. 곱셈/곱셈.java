import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Integer a = sc.nextInt();
        Integer b = sc.nextInt();
        Integer fi = a * ( b % 10 );
        Integer sec = a * ( b % 100 ) - fi;
        Integer thi = a * b - fi - sec;
        Integer fou = a * b;
        System.out.println( fi + "\n" + (sec / 10) + "\n" + (thi / 100) + "\n" + fou );
    }
}