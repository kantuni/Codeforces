import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) {
    BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
    try {
      int n = Integer.parseInt(buffer.readLine().trim());
      StringBuilder answer = new StringBuilder();
      if (n % 2 == 1) {
        answer.append(7);
        n -= 3;
      }
      while (n - 2 >= 0) {
        answer.append(1);
        n -= 2;
      }
      System.out.println(answer.toString());
    } catch (Exception e) {
      System.out.println(e.getMessage());
      e.printStackTrace();
    }
  }
}
