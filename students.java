import java.util.ArrayList;

class Classroom{
    public class Student{
        public int StudentID;
        public String name;
        public int age;
        public String grade;
        public Student(int StudentID,String name,int age,String grade){
            this.StudentID = StudentID;
            this.name = name;
            this.age = age;
            this.grade = grade;
        }
    }
    ArrayList<Student> Students;
    int ClassID;
    public Classroom(int i){
        ClassID = i;
        Students = new ArrayList<Student>();
    }
    public void AddStudent(int StudentID,String name,int age,String grade){
        Students.add(new Student(StudentID,name,age,grade));
    }
    public void Remove(int StudentID){
        for(int i = 0;i < Students.size();i++){
            if(Students.get(i).StudentID == StudentID){
                Students.remove(i);
                break;
            }
        }
    }
    public void Display(){
        System.out.println("Displaying the students of class " + ClassID);
        System.out.println("============================================================================");
        for(Student student : Students){
            System.out.println("StudentID = " + student.StudentID);
            System.out.println("Name = " + student.name);
            System.out.println("Age = " + student.age);
            System.out.println("Grade = " + student.grade);
        }
        System.out.println("============================================================================");
    }
}

public class students {
    public static void main(String[] args){
        int ClassID = 0;
        Classroom C = new Classroom(ClassID);
        C.AddStudent(1,"A",16,"A");
        C.AddStudent(2,"B",17,"B");
        C.AddStudent(3,"C",18,"C");
        System.out.println("Before removing the student");
        C.Display();
        C.Remove(2);
        System.out.println("After removing the student");
        C.Display();
        //create new classroom
        ClassID++;
        Classroom C2 = new Classroom(ClassID);
        //create new list
        C2.AddStudent(11,"A",16,"A");
        C2.AddStudent(12,"B",17,"B");
        C2.AddStudent(13,"C",18,"C");
        System.out.println("Before removing the student");
        C2.Display();
        C2.Remove(12);
        System.out.println("After removing the student");
        C2.Display();
    }
}
