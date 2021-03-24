#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <dirent.h>
#include <filesystem>
using namespace std;

#if defined ( __linux ) || ( __unix__ )
    const bool OS = true;
#else
    const bool OS = false;
#endif

char alphabetlower[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char integers[10] = {'0','1','2','3','4','5','6','7','8','9'};
string alphabetlower_ = "abcdefghijklmnolpqrstuvwxyz";
string integers_ = "0123456789";
string symbols = "/*-+=([]){}~#";

unsigned int seconde = 1000000;
string reset("\u001b[0m");
string red("\u001b[31m"), blue("\u001b[34m"), cyan("\u001b[36m"), yellow("\u001b[33m"), green("\u001b[32m");
string bwhite("\u001b[47m"), bblue("\u001b[44m");
string bold("\u001b[1m");
auto spd1(100ms), spd2(90ms), spd3(80ms), spd4(70ms), spd5(60ms), spd6(50ms), spd7(40ms), spd8(30ms);

struct product {
    int ID;
    string nameof;
    int stocknow;
    double price;
};
struct parapharmacie {
    int solded;
    int money;
    vector<string> products;
};

string actionPRINTING(string sentence, auto speed ) {
    for (int i = 0; i < sentence.length(); i++) {
        cout << sentence[i] << flush;
        this_thread::sleep_for(speed);
    };
    return sentence;
};
string backgroudcolorful(string text, string backgroud){
    return backgroud+text;
};
string colorfulPRINTING(string text, string color) {
    return color+text;
};

bool enterstrToTint(string str) {
    bool er;
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < alphabetlower_.size(); j++) {
            if (str[i] == alphabetlower_[j] ) {
                er = false;
                return er = false;
            } else { er = true; }
        } 
    }
    return er;
}
bool enterstrToTstr(string str) {
    bool er;
    string invalid = integers_ + symbols;
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < invalid.size(); j++) {
            if (str[i] == invalid[j] ) {
                er = false;
                return er = false;
            } else { er = true; }
        } 
    }
    return er;
};



bool IsPathExist(const string &s) {
  struct stat buffer;
  return (stat (s.c_str(), &buffer) == 0);
};
string pathnewfileproducts(int ID_newproduct) {
    string namefile = "_" + to_string(ID_newproduct);
    return "products/"+namefile +".txt";
};
int stringtoint(string str) {
    int n;
    n = stoi(str);
    return n;
};
bool mkdir(const char *__dirname) {
    bool created;
    if (mkdir( __dirname, 0777) == -1) { created = false; } else { created = true; };
    return created;
};
void welekom(int myI) {
    if (myI == 0 ) { 
        actionPRINTING(colorfulPRINTING("\t\tWELCOME TO THE CONSOLE MANAGING SYSTEM\n", yellow), spd8); cout << flush;
    } else { cout << yellow << "\t\tWELCOME TO THE CONSOLE MANAGING SYSTEM" << reset << endl; }
};
string refreshnumberofproducts() {
    string line;
    system("bash checkNumber.sh");
    ifstream thefile("_0.txt");
    thefile >> line;
    thefile.close();
    return line;
};
int inputChoice(char choice) {
    int newone;
    cin >> choice;
    newone = static_cast<int>(choice);
    return newone;
};
void indexPRINCIPAL(bool actP) {
    for (int i = 0; i < 70; i++){ cout << backgroudcolorful("*", bwhite);} cout << reset << endl;
    cout << backgroudcolorful("**", bwhite) << reset << colorfulPRINTING("\t1- Sold a product", red) << reset <<endl;
    cout << backgroudcolorful("**", bwhite) << reset << colorfulPRINTING( "\t2- See all available products statistiques", red) << reset << endl;
    cout << backgroudcolorful("**", bwhite) << reset << colorfulPRINTING("\t3- Add new product", red) << reset << endl;
    cout << backgroudcolorful("**", bwhite) << reset << colorfulPRINTING("\t4- Add new information for a product", red) << reset << endl;
    cout << backgroudcolorful("**", bwhite) << reset << colorfulPRINTING("\t5- Quit", red) << reset << endl;
    for (int i = 0; i < 70; i++){ cout << backgroudcolorful("*", bwhite);} cout << reset << endl;
};
int staticI(int i) {
    static int n = i;
    return ++n;
};
int AddNewProduct(int nowID) {
    nowID = staticI(nowID);
    string nameof, stocknow, price;
    product new_;
    cout << "Enter name of product : ";
    while (!enterstrToTstr(nameof) ) {
        cin >> nameof;
        cerr << "Enter a string !" << endl;
    }
    new_.nameof = nameof;
    cout << "Enter the quantity in stock now : "; 
    while (!enterstrToTint(stocknow) ) {
        cin >> stocknow;
        cerr << "Enter a integer !" << endl;
    }
    new_.stocknow = stringtoint(stocknow);
    cout << "Enter price : ";
    while (!enterstrToTint(price) ) {
        cin >> price;
        cerr << "Enter a integer !" << endl;
    }
    new_.price = stod(price);
    ofstream newproduct (pathnewfileproducts(nowID));
    newproduct << nowID << "\n" << new_.nameof << "\n" << new_.price << "\n" << new_.stocknow << endl;
    newproduct.close();
    return nowID;
};


int main() {
    if (OS) {
        mkdir("products");
        string mine;
        bool actionP = true;
        int i = 0;
        usleep(seconde);
        while (true and (mine[0] != '5')) {
            system("clear");
            welekom(i);
            cout << reset;
            indexPRINCIPAL(actionP);
            cout << "Enter your choice : " << cyan;
            cin >> mine;
            cout << reset;
            if (mine[0] == '4') {
                ofstream activated ("products/_activated.txt "); 
                activated << "true" << endl; 
                activated.close();
                AddNewProduct(stoi(refreshnumberofproducts()));
            } else if (mine[0] == '1') {
                
            } else if (mine[0] == '2') {
                
            } else if (mine[0] == '3') {
                
            } else {
                
            }
            cout << reset;
            i++;
        };
        remove("_0.txt");
        return EXIT_SUCCESS;
    } else { 
    cout << " windows is not comming soon haha." << endl; 
    return EXIT_FAILURE; 
    
    }
}
