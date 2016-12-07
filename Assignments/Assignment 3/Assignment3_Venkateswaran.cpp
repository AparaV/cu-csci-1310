/*Assignment 3 CSCI 1310 Recitation 101
**Written by Aparajithan Venkateswaran
**TA: Camilla Lambrocco
**Note: Please use a C++11 compiler. Otherwise the program will fail to compile as std::stoi() function is available only in C++11
*/

#include <iostream>
#include <limits>

using namespace std;

const string NO_TYPE = "NO_ITEM";
const int NO_PRICE = -1;

/*An Element of Message Board*/
class Element{
public:
    string type = NO_TYPE;//auto initialize
    int price = NO_PRICE;//auto initialize
};

/*Function Prototypes*/
int printChoices();//prints available choices and returns the user's choice as an integer
string charToString(char type);//converts char to string for ease of comparison
void addElement(Element msgBoard[20], char type, int price);//adds the user's choice of element to the message board
void searchElement(Element msgBoard[20], char type, int price);//searches the message board for available items on sale
void printMsgBoard(Element msgBoard[20]);//prints the message board
char isValid(char input);//checks validity of input
int isValid(int input);//checks validity of input

/*Main Program Begins*/
int main(){

    int choice = 1;
    char type;
    int price;
    Element msgBoard[20];//an array of elements. Each element has a type(string) and price(int)

    cout << "Press Enter to Begin." << endl;

    while(choice != 4){
        choice = printChoices();

        if(choice == 1){
            cout << "Enter the item type - b, m, d, t, c:" << endl;
            cin >> type;
            type = isValid(type);
            cout << "Enter the item cost:" << endl;
            cin >> price;
            price = isValid(price);
            addElement(msgBoard, type, price);
            continue;
        }

        if(choice == 2){
            cout << "Enter the item type - b, m, d, t, c:" << endl;
            cin >> type;
            type = isValid(type);
            cout << "Enter the maximum item cost:" << endl;
            cin >> price;
            price = isValid(price);
            searchElement(msgBoard, type, price);
            continue;
        }

        if(choice == 3){
            printMsgBoard(msgBoard);
            continue;
        }

    }

    cout << "Application exited." << endl;

    return 0;
}
/*Main Program Ends*/

/*Print Choices*/
int printChoices(){
    string choice;
    cin.ignore();//flush residual characters

    while(true){
        cout << "1. Insert an item." << endl;
        cout << "2. Search for an item." << endl;
        cout << "3. Print the message board." << endl;
        cout << "4. Quit" << endl;
        getline(cin, choice);

        //Exception Handling for std::stoi
        try{
            stoi(choice);
            if(stoi(choice) > 0 && stoi(choice) < 5){
                cout << endl;
                return stoi(choice);
            }
            else{
                cout << "Please enter a number that corresponds to a valid option." << endl;
                continue;
            }
        }
        catch(invalid_argument){
            cout << "Please enter a number that corresponds to a valid option." << endl;
        }
        catch(out_of_range){
            cout << "Please enter a number that corresponds to a valid option." << endl;
        }
    }

}

/*Char To String*/
string charToString(char type){
    if(type == 'b'){
        return "Bike";
    }
    else if(type == 'm'){
        return "Microwave";
    }
    else if(type == 'd'){
        return "Dresser";
    }
    else if(type == 't'){
        return "Truck";
    }
    else if(type == 'c'){
        return "Chicken";
    }
    else{
        return "NULL";
    }
}

/*Add Element to Message Board*/
void addElement(Element msgBoard[20], char type, int price){
    bool full = true;

    for(int i = 0; i < 20; ++i){
        //Checking for the next empty spot
        if(msgBoard[i].type == NO_TYPE){
            full = false;
            //Adding item
            msgBoard[i].type = charToString(type);
            msgBoard[i].price = price;
            cout << "Item Successfully Added." << endl << endl;
            break;
        }
    }

    //If the message board is full
    if(full){
        cout << "The Message Board is currently full." << endl << endl;
    }
}

/*Search Element and Delete it*/
void searchElement(Element msgBoard[20], char type, int price){
    bool success = false;
    int index = -1;
    int sold_price = -1;
    int length = 0;//number of items on the message board
    string type_conv = charToString(type);

    //checking correctness of item type
    if(type_conv == "NULL"){
        cout << "Please check your item type and/or price" << endl;
        return;
    }

    //searching for next available item
    for(int i = 0; i < 20; ++i){
        if(msgBoard[i].type == type_conv){
            if(msgBoard[i].price <= price){
                index = i;
                sold_price = msgBoard[i].price;
                success = true;
            }
        }
        if(msgBoard[i].type == NO_TYPE){
            length = i+1;
            break;
        }
    }

    //Deleting Element
    if(success){
        for(int i = index; i < length - 1; ++i){
            msgBoard[i].type = msgBoard[i+1].type;
            msgBoard[i].price = msgBoard[i+1].price;
        }
        msgBoard[length].type = NO_TYPE;
        msgBoard[length].price = NO_PRICE;
        cout << "Sold " << type_conv << " for $ " << sold_price << endl << endl;
    }
    else{
        cout << "Item not found." << endl << endl;
    }

}

/*Print Message Board*/
void printMsgBoard(Element msgBoard[20]){
    bool occupied = false;
    cout << "MESSAGE BOARD" << endl << endl;

    //prints message board
    for(int i = 0; i < 20; ++i){
        if(msgBoard[i].type != NO_TYPE){
            cout << msgBoard[i].type << " : $ " << msgBoard[i].price << endl;
            occupied = true;
        }
    }

    //if the message board is empty
    if(!occupied){
        cout << "The message board is empty. Add some items and try again." << endl << endl;
    }
    cout << "\nPress Enter to Continue." << endl;
}

/*Validity of input*/
char isValid(char input){
    char type = input;

    do{
        if(type == 'b' || type == 'm' || type == 'd' || type == 't' || type == 'c'){
            return type;
        }
        else{
            cout << "Not a valid type. Try again." << endl;
            cout << "\nEnter the item type - b, m, d, t, c:" << endl;
            cin >> type;
        }
    }while(true);
}

int isValid(int input){
    int price = input;

    while(!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number. Try again." << endl;
        cout << "Enter the item cost:" << endl;
        cin >> price;
    }

    return price;
}
