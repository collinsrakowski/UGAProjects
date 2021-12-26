package cs1302.example;
import cs1302.utility.MyMethods;
public class Hello {
    public static void main(String[] args) {
	int a;
	int b;
	int c;
	java.util.Scanner keyboard = new java.util.Scanner(System.in);
	System.out.println("Enter your first number.");
	a = keyboard.nextInt();
	System.out.println("Enter your second number.");
	b = keyboard.nextInt();	
	c = MyMethods.maxCheck(a, b);
	System.out.println(c + " is the greater number");
    }
}
	
