#include<iostream>
#include<string>
#include<limits>

using namespace std;

struct Book
{
    string title;
    string author;
    int publication_year;
    string genre;
};

void inputDetails(Book books[6]);
void categorizeBooks(const Book books[6], Book fictionalBooks[6], Book nonFictionalBooks[6], int& fictionCount, int& nonFictionCount);
Book findEarliestBook(const Book books[], int count);
void displayBookDetails(const Book books[], int count, const string& category);

int main()
{
    Book books[6], fictionalBooks[6], nonFictionalBooks[6];
    int fictionCount = 0, nonFictionCount = 0;

    inputDetails(books);

    categorizeBooks(books, fictionalBooks, nonFictionalBooks, fictionCount, nonFictionCount);

    if (fictionCount > 0)
    {
        Book earliestFiction = findEarliestBook(fictionalBooks, fictionCount);
        displayBookDetails(fictionalBooks, fictionCount, "Fiction");
        cout << "Earliest Fiction Book: " << endl;
        cout << "Title: " << earliestFiction.title << endl;
        cout << "Author: " << earliestFiction.author << endl;
        cout << "Publication Year: " << earliestFiction.publication_year << endl;
        cout << "Genre: " << earliestFiction.genre << endl << endl;
    }
    else
    {
        cout << "No Fictional Books Found." << endl << endl;
    }

    if (nonFictionCount > 0)
    {
        Book earliestNonFiction = findEarliestBook(nonFictionalBooks, nonFictionCount);
        displayBookDetails(nonFictionalBooks, nonFictionCount, "Non-Fiction");
        cout << "Earliest Non-Fiction Book: " << endl;
        cout << "Title: " << earliestNonFiction.title << endl;
        cout << "Author: " << earliestNonFiction.author << endl;
        cout << "Publication Year: " << earliestNonFiction.publication_year << endl;
        cout << "Genre: " << earliestNonFiction.genre << endl;
    }
    else
    {
        cout << "No Non-Fictional Books Found." << endl;
    }

    return 0;
}

void inputDetails(Book books[6])
{
    for (int i = 0; i < 6; i++)
    {
        cout << "Enter details for Book " << i + 1 << endl;
        cout << "Title: ";
        cin.ignore();
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "Publication Year: ";
        cin >> books[i].publication_year;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Genre (Fiction(F)/Non-fiction(N)): ";
        getline(cin, books[i].genre);
        cout << endl;
    }
}

void categorizeBooks(const Book books[6], Book fictionalBooks[6], Book nonFictionalBooks[6], int& fictionCount, int& nonFictionCount)
{
    for (int i = 0; i < 6; i++)
    {
        if (books[i].genre == "f" || books[i].genre == "F")
        {
            fictionalBooks[fictionCount++] = books[i];
        }
        else if (books[i].genre == "n" || books[i].genre == "N")
        {
            nonFictionalBooks[nonFictionCount++] = books[i];
        }
    }
}

Book findEarliestBook(const Book books[], int count)
{
    Book earliestBook = books[0];
    for (int i = 1; i < count; i++)
    {
        if (books[i].publication_year < earliestBook.publication_year)
        {
            earliestBook = books[i];
        }
    }
    return earliestBook;
}

void displayBookDetails(const Book books[], int count, const string& category)
{
    cout << "Details for " << category << " books: " << endl << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Publication Year: " << books[i].publication_year << endl;
        cout << "Genre: " << books[i].genre << endl;
        cout << "*****" << endl;
    }
}