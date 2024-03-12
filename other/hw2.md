```java
import java.util.Scanner;

class Person {
    String name;
    double height;
    double weight;
    double bmi;
}

public class HW2480 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Person per[] = new Person[2];

        for (int i = 0; i < 2; i++) {
            per[i] = new Person(); // Initialize each person object

            System.out.print("名字: ");
            per[i].name = sc.next();

            System.out.print("身高: ");
            per[i].height = sc.nextDouble();

            System.out.print("體重: ");
            per[i].weight = sc.nextDouble();

            per[i].bmi = per[i].weight / (per[i].height * per[i].height);
            System.out.println("=====下面一位=======");
        }

        for (int i = 0; i < 2; i++) {
            System.out.println(
                    per[i].name + "  身高:" + per[i].height + "  體重:" + per[i].weight + "  BMI:" + per[i].bmi);

            String bmi_winer = per[0].bmi > per[1].bmi ? per[0].name : per[1].name;
            String h_loser = per[0].height < per[1].height ? per[0].name : per[1].name;
            System.out.println(bmi_winer + " BMI 比較重");
            System.out.println(h_loser + " 比較矮");
        }

        sc.close();
    }
}
```
