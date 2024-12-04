#include<iostream>
#include<iomanip>
#include<string.h>  // Required for strcmp

using namespace std;

class book
{
    public:

    char title[20];
    char author[20];
    char publisher[20];

    int price;
    int stock;

    void accept()
    {
        cout<<"Enter book title :";
        cin>>title;
        cout<<"Enter book author :";
        cin>>author;
        cout<<"Enter book publisher :";
        cin>>publisher;

        cout<<"Enter book price :";
        cin>>price;
        cout<<"Enter book stock :";
        cin>>stock;

    }

    void display()
    {
        cout<<left<<setw(10)<<title
                  <<setw(10)<<author
                  <<setw(10)<<publisher
                  <<setw(10)<<price
                  <<setw(10)<<stock
                  <<endl;
    }
    

};

int main()
{
    int i,j,ch,size,temp,Quantity;
    char temptitle[20],tempauthor[20];
    book b;
    book obj[20];
    cout << "Enter the number of books: ";
    cin >> size;
    
    do{
    cout<<"\n1.accept\n2.display\n3.sort\n4.buy\n5.Exit\n";
    cin>>ch;

    switch(ch){

        case 1:
        for(i=0;i<size;i++){
        obj[i].accept();
        }
        break;

         case 2:
         cout<<left<<setw(10)<<"title"
                  <<setw(10)<<"author"
                  <<setw(10)<<"publisher"
                  <<setw(10)<<"price"
                  <<setw(10)<<"stock"
                  <<endl;
        cout<<"................................"<<endl;
        for(i=0;i<size;i++){
        obj[i].display();
        }
        break;

        case 3:
        for(i=0;i<size-1;i++){
            for(j=i+1;j<size;j++){
                if(obj[i].price<obj[j].price){

                 book temp=obj[i];
                    obj[i]=obj[j];
                    obj[j]=temp;
                }
            }
        }

        cout<<left<<setw(10)<<"title"
                  <<setw(10)<<"author"
                  <<setw(10)<<"publisher"
                  <<setw(10)<<"price"
                  <<setw(10)<<"stock"
                  <<endl;
        cout<<"................................"<<endl;

    for(i=0;i<size;i++){
        obj[i].display();
    }
    break;

     case 4:
            // Case 4: Buy a book
            cout << "Enter Book Title: ";
            cin >> temptitle;
            cout << "Enter Book Author: ";
            cin >> tempauthor;

            for (i = 0; i < size; i++) {
                // Corrected to use strcmp for string comparison
                if (strcmp(obj[i].title, temptitle) == 0 && strcmp(obj[i].author, tempauthor) == 0) {
                    cout << "\n\n______Book is Available______\n\n";
                    cout << "Available Stock is: " << obj[i].stock << "\n\n";
                    cout << "How many books do you want: ";
                    cin >> Quantity;

                    if (obj[i].stock >= Quantity) {
                        int cost = Quantity * obj[i].price;
                        obj[i].stock -= Quantity;
                        cout << "\n\nTotal cost of these books is: " << cost << "\n\n";
                    } else {
                        cout << "\n\nNot enough stock available.\n";
                    }
                    break;
                }
            }

            if (i == size) {
                cout << "Book not found\n\n";
            }
            break;


    }
    }while(ch!=5);

return 0;
}