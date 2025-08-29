import java.util.Scanner;

public class aplusb{
    public static void main(String[] args){
        Scanner jvin = new Scanner(System.in);

        int a = jvin.nextInt();
        int b = jvin.nextInt();
        int c = a + b;

        System.out.println("expr is " + c);
    }
}