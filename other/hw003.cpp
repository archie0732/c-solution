#include <bits/stdc++.h>


using namespace std;

class Book{
    private:
        string title, author, publisher;
        int price,year;
    public :
        void set_title(string t){
            title = t;
        }
        void set_author(string a){
            author = a;
        }
        void set_price(int p){
            price = p;
        }
        void set_year(int y){
            year = y;
        }
        void set_publisher(string p){
            publisher = p;
        }

        string get_title(){
            return title;
        }
        string get_author(){
            return author;
        }

        int get_price(){
            return price;
        }
        int get_year(){
            return year;
        }
        string get_publisher(){
            return publisher;
        }

};

class Bookstore
{
private:
    string name;
    

public:
    vector<Book> book;

    void add_book(Book b){
        book.push_back(b);
    }

    void remove_book(Book b)
    {
        for (auto it = book.begin(); it != book.end(); ++it)
        {
            if (it->get_title() == b.get_title() && it->get_author() == b.get_author() && it->get_price() == b.get_price() && it->get_year() == b.get_year() && it->get_publisher() == b.get_publisher())
            {
                book.erase(it);
            }
        }
    }

    vector<Book> search_book_by_title(string title){
        vector<Book> v;
        for(auto it:book){
            if(it.get_title() == title){
                v.push_back(it);
            }
        }

        return v;
    }

    vector<Book> search_book_by_author(string author){
        vector<Book> v;
        for(auto it:book){
            if(it.get_author()==author){
                v.push_back(it);
            }
        }
        return v;
    }
    vector<Book> search_book_by_publisher(string publisher){
        vector<Book> v;
        for(Book it :book){
            if(it.get_publisher()==publisher){
                v.push_back(it);
            }
        }

        return v;
    }
};




int main(){

    int n;
    cin>>n;
    string bookstore_name;
    Bookstore bookstore;
    while(n--){
        string book_name,author,publisher;
        int price,year;

        cin>>book_name>>author>>price>>year>>publisher;
        
        Book new_book;
        new_book.set_title(book_name);
        new_book.set_author(author);
        new_book.set_price(price);
        new_book.set_year(year);
        new_book.set_publisher(publisher);

        // Add the book to the bookstore
        bookstore.add_book(new_book);
    }
    cin>>bookstore_name;

    cout<<"Welcome to BookStore "<<bookstore_name<<"!"<<endl;

    cout<<"Here are our books:"<<endl;

    if(bookstore.book.empty()){
        cout<<"the bookstore are sale out!!!"<<endl;
    }

    for(auto it:bookstore.book){
        cout<<it.get_title()<<" by "<<it.get_author()<<", "<<it.get_price()<<" NTD,"<<it.get_year()<<", "<<it.get_publisher()<<endl;
    }
    cout<<"Search books:"<<endl;

    string name,publisher,author;
    //cout << "=====================================" << endl;
    while (cin >> name>>author >> publisher)
    {
        auto books_by_author = bookstore.search_book_by_author(author);
        auto books_by_publisher = bookstore.search_book_by_publisher(publisher);
        
        vector<Book> ans,tem;

        for(auto it:books_by_author){
            tem.push_back(it);
        }

        for(auto it:books_by_publisher){
            
            for(auto i:tem){
                if(i.get_author()==it.get_author()&&i.get_title()==it.get_title()&&i.get_publisher()==it.get_publisher()){
                    ans.push_back(i);
                    break;
                }
            }
            
        }
        if(ans.empty()){
            cout<<"No match book!!!!"<<endl;
        }
        for(auto it:ans){
            cout << it.get_title() << " by " << it.get_author() << ", " << it.get_price() << " NTD," << it.get_year() << ", " << it.get_publisher() << endl;
        }
        cout<<"=================="<<endl;
        cout << "Search books:" << endl;
    }

    return 0;
}
