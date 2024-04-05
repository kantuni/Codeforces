import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();
    StringBuilder answer = new StringBuilder();
    if (n % 2 == 1) {
      answer.append(7);
      n -= 3;
    }
    while (n > 0) {
      answer.append(1);
      n -= 2;
    }
    System.out.println(answer.toString());
  }
}
