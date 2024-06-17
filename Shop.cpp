#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum Category {
    CONSOLES,
    SMARTPHONES,
    KEYBOARDS
};
struct Products {
    int id;
    string name;
    Category category;
    float price;
    int quantity;
    Products() {};
    Products(int id, string name, Category category, float price, int quantity) : id(id), name(name), category(category), price(price), quantity(quantity) {};
};
struct Shop {
    int size = 0;
    Products* arrShop = new Products[size];
};
Category returnCat(string a) {
    if (a == "0") return CONSOLES;
    else if (a == "1") return SMARTPHONES;
    else if (a == "2") return KEYBOARDS;
}
int ID = 0;
void addProduct(Shop& s, string name, Category cat, float price, int quantity) {
    Products* buf = new Products[s.size + 1];
    for (int i = 0; i < s.size; i++) {
        buf[i] = s.arrShop[i];
    }
    buf[s.size++] = Products{ ID++, name, cat, price, quantity };
    delete[] s.arrShop;
    s.arrShop = buf;
}
void delProduct(Shop& s, int pr) {
    Products* buf = new Products[s.size - 1];
    for (int i = 0; i < pr - 1; i++) {
        buf[i] = s.arrShop[i];
    }
    for (int i = pr; i < s.size; i++) {
        buf[i - 1] = s.arrShop[i];
    }
    delete[] s.arrShop;
    s.arrShop = buf;
    s.size--;
}
void showProducts(Shop s) {
    string a;
    for (int i = 0; i < s.size; i++) {

        if (s.arrShop[i].category == 0) a = "Consoles";
        else if (s.arrShop[i].category == 1) a = "SMARTPHONES";
        else a = "Keyboards";
        cout << s.arrShop[i].name << ' ' << "(ID - " << s.arrShop[i].id << ", Category - " << a << ", Price - " << s.arrShop->price << ", Quantity - " << s.arrShop->quantity << ')' << endl;
    }

}
void showByCategory(Shop s, int a) {
    string b;
    for (int i = 0; i < s.size; i++) {
        if (s.arrShop[i].category == 0) b = "Consoles";
        else if (s.arrShop[i].category == 1) b = "SMARTPHONES";
        else b = "Keyboards";
        if (a == s.arrShop[i].category) cout << s.arrShop[i].name << ' ' << "(ID - " << s.arrShop[i].id << ", Category - " << b << ", Price - " << s.arrShop->price << ", Quantity - " << s.arrShop->quantity << ')' << endl;
        
    }

}
void showByName(Shop s, string name) {
    for (int i = 0; i < s.size; i++) {
        if (name == s.arrShop[i].name) cout << s.arrShop[i].quantity << endl;;

    }
}
int numStr = 0;
int numStrFile() {
    ifstream in("shop.txt");
    string str;
    if (in.is_open()) {
        while (getline(in, str)) {
            numStr++;

        }
    }
    in.close();
    return numStr;
}

void saveFile(Shop s) {
    ofstream out;
    out.open("shop.txt");
    
    if (out.is_open()) {
        for (int i = 0; i < s.size; i++) {
                out << s.arrShop[i].name << ';' << s.arrShop[i].id << ';' << s.arrShop[i].category << ';' << s.arrShop[i].price << ';' << s.arrShop[i].quantity << ';' << endl;
        }
    }
    
}

void readFile(Shop& s) {
    ifstream in("shop.txt");
    string str;
    int i = 0;
    int a = 0;
    Products* buf = new Products[numStrFile()];
    if (in.is_open()) {
            while(i < numStrFile()){
            if (a == 0) {
                getline(in, str, ';');
                buf[i].name = str;
                a++;

            }
            else if (a == 1) {
                getline(in, str, ';');
                buf[i].id = stoi(str);
                a++;

            }
            else if (a == 2) {
                getline(in, str, ';');
                buf[i].category = returnCat(str);
                a++;
            }
            else if (a == 3) {
                getline(in, str, ';');
                buf[i].price = stof(str);
                a++;
            }
            else if (a == 4) {
                getline(in, str, ';');
                buf[i].quantity = stoi(str);
                i++;
                a = 0;
            }
        }
    }
    delete[] s.arrShop;
    s.arrShop = buf;
}

int main() {
    int choice;
    bool exit = false;
    Shop s1;
    //numStrFile();
    int num = 0;
    if (numStrFile() > 0) {
        readFile(s1);
    }
    while (exit == false) {
        cout << endl;
        cout << " 1 - Add product \n 2 - Delete product \n 3 - Show all product \n 4 - Show product by category \n 5 - Show quanity by name\n 0 - EXIT" << endl;
        cin >> choice;
        switch (choice) {
        case 0:
            if (num != 0) {
                saveFile(s1);
            }
            exit = true;
            break;
        case 1:
        {
            string name;
            int cat;
            float price;
            int quantity;
            cout << "Name product: ";
            getline(cin, name);
            Category categ;
            cout << "CONSOLE - 0, SMARTPHONES - 1, KEYBOARDS - 2\nCategory product:";
            cin >> cat;
            categ = Category(cat);
            cout << "PRICE: ";
            cin >> price;
            cout << "QUANTITY: ";
            cin >> quantity;
            addProduct(s1, name, categ, price, quantity);
            cout << endl << "Product added" << endl;
            num++;
            break;
        }
        case 2:
            int a;
            cout << endl << "Which product should I remove?: " << endl;
            cin >> a;
            delProduct(s1, a);
            cout << "Product deleted";
            break;
            num++;
        case 3:
            cout << endl;
            showProducts(s1);
            break;
        case 4:
            int cat;
            cout << "CONSOLE - 0, SMARTPHONES - 1, KEYBOARDS - 2\nCategory product:";
            cin >> cat;
            showByCategory(s1, cat);
            break;
        case 5: {
            string name;
            cout << "What quantity of product do you want to see?: ";
            cin >> name;
            showByName(s1, name);
            break;
        }
        default:
            break;
        }



    }

}
