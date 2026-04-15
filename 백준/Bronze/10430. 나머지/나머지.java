import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Integer a = sc.nextInt();
        Integer b = sc.nextInt();
        Integer c = sc.nextInt();
        Integer one = ( a + b ) % c;
        Integer two =  (( a % c ) + ( b % c )) % c;
        Integer three = ( a * b ) % c;
        Integer four = (( a % c ) * ( b % c )) % c;
        System.out.println( one + "\n" + two + "\n" + three + "\n" + four );
    }
}