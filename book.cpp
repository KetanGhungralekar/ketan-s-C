#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Book{
    public:
    string title;
    string author;
    int ISBN;
    bool available;
    Book(string title,string author,int ISBN,bool available){
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
        this->available = available;
    }
};
class Library{
    public:
    vector <Book> books;
    Library(){
        this->books = books;
    }
    void Add(Book obj){
        books.push_back(obj);
    }
    void Remove(int ISBN){
        for (auto i=0;i<books.size();i++){
            if (books[i].ISBN == ISBN){
                books.erase(books.begin()+i);
                break;
            }
        }
    }
    void Display(){
        cout<<"Displaying the books available in the library"<<endl;
        cout<<"==================================================="<<endl;
        for (auto i:books){
            if (i.available){
            cout <<"Title of Book = "<< i.title <<endl;
            cout<<"Author = "<<i.author <<endl;
            cout<< "ISBN number = " << i.ISBN <<endl;
            }
        }
        cout<<"==================================================="<<endl;
    }
};
int main(){
    //create sample data for 6 books
    Book b1 = Book("The Alchemist","Paulo Coelho",123456789,true);
    Book b2 = Book("The Monk Who Sold His Ferrari","Robin Sharma",123456788,true);
    Book b3 = Book("The Power of Now","Eckhart Tolle",123456787,true);
    Library L = Library();
    L.Add(b1);
    L.Add(b2);
    L.Add(b3);
    cout<<"Before removing the book"<<endl;
    L.Display();
    L.Remove(123456789);
    cout<<"After removing the book"<<endl;
    L.Display();
    return 0;
}