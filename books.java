import java.util.ArrayList;
import java.util.Scanner;

public class books{
    public static void main(String[] args) {
        // Create sample data for 6 books
        Book b1 = new Book("The Alchemist", "Paulo Coelho", 123456789, true);
        Book b2 = new Book("The Monk Who Sold His Ferrari", "Robin Sharma", 123456788, true);
        Book b3 = new Book("The Power of Now", "Eckhart Tolle", 123456787, true);
        Scanner sc  = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(s);
        Library L = new Library();
        L.add(b1);
        L.add(b2);
        L.add(b3);
        System.out.println("Before removing the book");
        L.display();
        L.remove(123456789);
        System.out.println("After removing the book");
        L.display();
    }
}
class Book {
    public String title;
    public String author;
    public int ISBN;
    public boolean available;
    public Book(String title, String author, int ISBN, boolean available) {
        this.title = title;
        this.author = author;
        this.ISBN = ISBN;
        this.available = available;
    }
}
class Library {
    public ArrayList<Book> books;
    public Library() {
        books = new ArrayList<>();
    }
    public void add(Book obj) {
        books.add(obj);
    }
    public void remove(int ISBN) {
        for (int i = 0; i < books.size(); i++) {
            if (books.get(i).ISBN == ISBN) {
                books.remove(i);
                break;
            }
        }
    }
    public void display() {
        System.out.println("Displaying the books available in the library");
        System.out.println("======================================================");
        for (Book book : books) {
            if (book.available) {
                System.out.println("Title of Book = " + book.title);
                System.out.println("Author = " + book.author);
                System.out.println("ISBN number = " + book.ISBN);
            }
        }
        System.out.println("======================================================");
    }
}
