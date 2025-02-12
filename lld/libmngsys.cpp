#include <bits/stdc++.h>

using namespace std;

// R1: The system should be able to store the information about books and members of the library. Moreover, the complete log of the book borrowing process should also be stored.
// R2: Every book is supposed to have a unique identification number and other details including a rack number to help locate the book physically.
// R3: Every book should have an associated ISBN, title, author name, subject, and publication date.
// R4: There can be multiple copies of the book. Each copy will be recognized as a book item.
// R5: There can be two types of users, i.e., the librarian and the members.
// R6: Every user must have a library card with a unique card number.
// R7: One member can issue a maximum of 10 books at a time.
// R8: The member can issue a book for a maximum of 15 days.
// R9: Each book item can only be reserved by a single member.
// R10: The system should be able to keep a record of who issued or reserved a particular book and on which date.
// R11: The system should allow the user to renew the reserved book.
// R12: The system should send a notification if the book is not returned within the due date.
// R13: If the book is currently not available, then the member should be able to reserve it for whenever it is available.
// R14: The system should allow the user to search a book by its title, author name, subject, or publication date.
static int bIidCnt=0;

enum BookStatus{
    AVAILABLE,
    BORROWED,
    RESERVED
};

class Book{
    public:
    int bId;
    string title;
    string iSBN;
    string author;
    string subject;
    string publicationDate;

    Book(){}

    Book(int bId, string title, string iSBN, string author, string subject, string publicationDate)
        :bId(bId), title(title), iSBN(), author(author), subject(subject), publicationDate(publicationDate){};
};

class BookItem: public Book{
    public: 
    int bIid;
    int rackNo;
    BookStatus bookLendingStatus;
    BookStatus bookReservationStatus;
    int lentOn;
    int reservedOn;
    int lentTill;
    int reservedTill;
    BookItem(Book book, int bIid, int rack){
        this->bId = book.bId;
        this->bIid = bIid;
        this->rackNo = rack;
        this->title = book.title;
        this->author = book.author;
        this->iSBN = book.iSBN;
        this->subject = book.subject;
        this->publicationDate = book.publicationDate;
    }

};


struct Log{
    string action;
    int date;
    string user;
};

class Catalogue{
    public:
    map<string, int> booksByTitle;
    map<string, int> booksByAuthor;
    map<string, int> booksByPublicationDate;
    map<string, int> booksBySubject;
    map<int, vector<int>> books;
    map<int, BookItem*> bookItems;

    void addBook(Book book, int rack){
        BookItem *bookItem = new BookItem(book, ++bIidCnt, rack);
        booksByTitle[book.title] = book.bId;
        booksByAuthor[book.author] = book.bId;
        booksBySubject[book.subject] = book.bId;
        booksByPublicationDate[book.publicationDate] = book.bId;
        books[book.bId].push_back(bIidCnt);
        bookItems[bIidCnt] = bookItem;
    }

    int searchBookByTitle(string title){
        if(booksByTitle.count(title))
            return booksByTitle[title];
        return -1;
    }

    int searchBookBySubject(string subject){
        if(booksBySubject.count(subject))
            return booksBySubject[subject];
        return -1;
    }
};

Catalogue *catalogue=NULL;
vector<Log> logs;

class User{
    public:
    string name;
    string cardNum;
    string passwd;
    vector<int> booksLent;

    User(){}

    User(string name, string cardNum): name(name), cardNum(cardNum){};

    int searchBookByTitle(string title){
        return catalogue->searchBookByTitle(title);
    }

    int searchBookBySubject(string subject){
        return catalogue->searchBookBySubject(subject);
    }
    int checkoutBook(int bId, int date, int numDays){
        if(booksLent.size()==10){
            cout << "User has already lent 10 books\n";
            return -1;
        }
        if(numDays>15){
            cout << "User cannot borrow book for more than 15 days\n";
            return -1;
        }
        for(auto bookId: catalogue->books[bId]){
            auto b = catalogue->bookItems[bookId];
            if(b->bookLendingStatus == AVAILABLE && b->bookReservationStatus == AVAILABLE){
                booksLent.push_back(b->bIid);
                b->bookLendingStatus = BORROWED;
                b->lentOn = date;
                b->lentTill = date+numDays;
                Log borrowLog = {};
                borrowLog.action = "Borrowed Book";
                borrowLog.date = date;
                borrowLog.user = this->cardNum;
                logs.push_back(borrowLog);
                return b->bIid;
            }
        }
        cout << "Book is not available to be borrowed at date: " << date << endl;
        return -1;
    }

    double returnBook(int bIid, int date){
        BookItem *bookItem = catalogue->bookItems[bIid];
        if(date>bookItem->lentTill){
            cout << "Book is being returned late, Fine applicable!\n";
            double fineAmt = 10*(date-bookItem->lentTill);
            cout << "Please pay fine :"<< fineAmt << endl;
            return fineAmt;
        }
        Log borrowLog = {};
        borrowLog.action = "Returned Book";
        borrowLog.date = date;
        borrowLog.user = this->cardNum;
        logs.push_back(borrowLog);
        bookItem->lentOn = 0;
        bookItem->lentTill = 0;
        bookItem->bookLendingStatus = AVAILABLE;
        return 0;
    }

    int reserveBook(){return 0;}
};

class Librarian: public User{
    public:
    Librarian(){};

    Librarian(string name, string cardNum):User(name, cardNum){};

    void addBook(Book book, int rackNo){
        catalogue->addBook(book, rackNo);
    }

    void removeBook(int bIid){}
};

class Member: public User{
    public:
    Member(){};

    Member(string name, string cardNum):User(name, cardNum){};
};



class Library{
    private:
    Library(){
    }
    public:
    string name;
    string address;
    static Library *library;
    vector<Member*> members;
    vector<Librarian*> librarians;
    vector<Log> logs;

    static Library* getInstance(){
        if(library==NULL){
            library = new Library();
            catalogue = new Catalogue();
        }
        return library;
    }

    void addUser(Member *member){
        this->members.push_back(member);
    }

};

Library* Library::library = NULL;
void printLogs();

int main(){
    Library* myLibrary = Library::getInstance();
    Librarian *librarian = new Librarian("Bot", "11");
    librarian->cardNum = 11;
    librarian->name = "Bot";
    Book book1 = Book(101, "Harry Potter Prisoner of Azkaban", "ASJDH1134", "J. K. Rowling", "Fantasy", "02121998");
    librarian->addBook(book1, 12);
    Member *member = new Member("Member1", "211");
    int bId = member->searchBookBySubject("Fantasy");
    cout << bId << endl;
    int bIid = member->checkoutBook(bId, 17, 7);
    cout << bIid << endl;

    cout << member->returnBook(bIid, 21) << endl;
    printLogs();
}

void printLogs(){
    for(auto l: logs){
        cout <<"Action: "<< l.action << ", Date: " <<l.date <<", User: " << l.user << endl;
    }
}