import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;


/*
 * HW4
 * 資工一A
 * 411211480
 * 許育祁
 */

class Person {
    protected String name;

    public Person(String name) {
        this.name = name;
    }

    
    public String getName() {
        return name;
    }
}

class Student extends Person {
    private double height; // in cm
    private double weight; // in kg
    private int score;

    public Student(String name, double height, double weight) {
        super(name);
        this.height = height;
        this.weight = weight;
    }

    public double calculateBMI() {
        return weight / ((height / 100) * (height / 100));
    }

    public double getHeight() {
        return height;
    }

    public double getWeight() {
        return weight;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }
}

class Teacher extends Person {
    private double height; // in cm
    private double weight;

    public Teacher(String name, double height, double weight) {
        super(name);
        this.height = height;
        this.weight = weight;   
    }

}

class ClassManager extends Person {
    private String className="資工一A";
    private String[] course={"程設","進階程設","物件導向"};
    private List<Student> students;
    private Teacher teacher;

    public ClassManager(String name, String className, Teacher teacher) {
        super(name);
        this.className = className;
        this.students = new ArrayList<>();
        this.teacher = teacher;
    }

    public void addStudent(Student student) {
        students.add(student);
    }

    public void changeClassInfo() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("更新班級資訊:(原本名稱: "+className+")");
        this.className = scanner.nextLine();
        System.out.println("目前課表 1."+course[0]+" 2."+course[1]+" 3."+course[2]);
        System.out.println("輸入要更換課表");
        int num = scanner.nextInt();
        System.out.println("輸入名稱");
        course[num-1] = scanner.next();

    }

    public void displayAllBMI() {
        for (Student student : students) {
            System.out.println(student.getName() + "'s BMI: " + student.calculateBMI());
        }
    }

    public void generateRandomScores() {
        Random random = new Random();
        for (Student student : students) {
            int score = random.nextInt(41)+60;
            student.setScore(score);
        }
    }

    public void calculateSubjectStats() {
        Scanner scanner = new Scanner(System.in);


        int total = 0;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        for (Student student : students) {
            int score = student.getScore();
            total += score;
            if (score > max) {
                max = score;
            }
            if (score < min) {
                min = score;
            }
        }

        double average = (double) total / students.size();
        //System.out.println("Subject: " + subject);
        System.out.println("平均成績: " + average);
        System.out.println("最高: " + max);
        System.out.println("最低: " + min);
    }

    public void searchStudentByName() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("輸入要查詢人名:");
        String name = scanner.nextLine();

        for (Student student : students) {
            if (student.getName().equalsIgnoreCase(name)) {
                System.out.println("查詢到之學生資料:");
                System.out.println("Name: " + student.getName());
                System.out.println("Height: " + student.getHeight());
                System.out.println("Weight: " + student.getWeight());
                System.out.println("BMI: " + student.calculateBMI());
                System.out.println("分數: " + student.getScore());
                System.out.println();
                return;
            }
        }

        System.out.println("未找到該名學生");
        
    }
}

public class HW4_480 {

    public static void main(String[] args) {

        System.out.println(args.length);

        if (args.length % 3 != 0) {
            System.out.println("含非法資料");
            return;
        }

        // name cm kg
        int numStudents = args.length / 3;
        Student[] students = new Student[numStudents];
        for (int i = 0; i < numStudents; i++) {
            String name = args[i * 3];
            double height = Double.parseDouble(args[i * 3 + 1]); 
            double weight = Double.parseDouble(args[i * 3 + 2]); 
            students[i] = new Student(name, height, weight); 
        }

        
        int teacherArgsIndex = args.length - 3;
        String teacherName = args[teacherArgsIndex];
        double teacherHeight = Double.parseDouble(args[teacherArgsIndex + 1]);
        double teacherWeight = Double.parseDouble(args[teacherArgsIndex + 2]);
        Teacher teacher = new Teacher(teacherName, teacherHeight, teacherWeight);

        
        ClassManager classManager = new ClassManager("資工一A", "資工一A", teacher);

        
        for (Student student : students) {
            classManager.addStudent(student);
        }

        
        Scanner scanner = new Scanner(System.in);
        while (true) {

            System.out.println("\nMain Menu:");
            System.out.println("(1) 更改班級基本資訊");
            System.out.println("(2) 輸出全部同學之BMI");
            System.out.println("(3) 產生學生成績");
            System.out.println("(4) 算出平均、最高與最低分數");
            System.out.println("(5) 查詢學生基本資料");
            System.out.println("(6) Exit");

            System.out.print("請輸入選項: ");
            int choice = scanner.nextInt();
            System.out.println();

            switch (choice) {
                case 1:
                    classManager.changeClassInfo();
                    break;
                case 2:
                    classManager.displayAllBMI();
                    break;
                case 3:               
                    classManager.generateRandomScores();
                    break;
                case 4:
                    
                    classManager.calculateSubjectStats();
                    break;
                case 5:
                    
                    classManager.searchStudentByName();
                    break;
                case 6:
                    
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("非法輸入");
            }
        }
    }
}

