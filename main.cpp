// LIBRARIES :
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <unistd.h>
#include <chrono>
#include <thread>

// STANDART NAMESPACE :
using namespace std;

// MAKE THE CODE RUN JUST IN UNIX :
#if defined ( __linux ) || ( __unix__ )
    const char *nOS = "run";
#else
    const char *nOS = "drun";
#endif
// GLOBALE VARIABLES :
unsigned int seconde = 1000000;
string reset("\u001b[0m");
string red("\u001b[31m"), blue("\u001b[34m"), cyan("\u001b[36m"), yellow("\u001b[33m"), green("\u001b[32m");
string bwhite("\u001b[47m"), bblue("\u001b[44m");
string bold("\u001b[1m");
auto spd1(100ms), spd2(90ms), spd3(80ms), spd4(70ms), spd5(60ms), spd6(50ms), spd7(40ms), spd8(30ms);
// STRUCTES : 
struct product {
    int ID;
    string nameof;
    int stocknow;
    float price;
};
struct parapharmacie {
    int solded;
    vector<string> products;
};

// STYLING FUNCTIONS :
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
// FUNCTIONS ESSENTIAL :
void welekom() {
    int i = main();
    if (i == 0 ) { 
        actionPRINTING(colorfulPRINTING("\t\tWELCOME TO THE CONSOLE MANAGING SYSTEM\n", yellow), spd8); 
    } else { cout << yellow << "\t\tWELCOME TO THE CONSOLE MANAGING SYSTEM" << reset << endl; }
};
void refreshnumberofproducts() {
    string line;
    system("bash checkNumber.sh");
    ifstream thefile("numberofproducts.txt");
    thefile >> line;
    thefile.close();
    cout << line;
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
void MANAGER(int yours) {
    int numberofitems;
    switch (yours)
    {
    case 0:
        break;
    case 1:
        //
        break;
    case 2:
        break;
    case 3:
        //
        break;
    case 4:
        //
        break;
    case 5:
        //
        break;
    default:
        yours = 0;
        break;
    }
};

// MAIN FUNCTION :
int main() {
    char mine;
    bool actionP = true;
    int i = 0;
    usleep(seconde);
    while (true) {
        system("clear");
        welekom();
        cout << reset;
        indexPRINCIPAL(actionP);
        cout << "Enter your choice : " << cyan;
        mine = inputChoice(mine);
        cout << reset;
        MANAGER(mine);
        i++;
    };
    return i;
}
