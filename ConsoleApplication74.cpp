#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



class Detail {
private:
    int id=0, tmp=0;
    string name;
public:
    friend class Controller;
    Detail(){
        int defaultId = 1111111;
        id = defaultId;
    }
    int idSetter(int number){
        if (number > 9999999 || number < 1000000) {
            cout << "Input number must be >1000000 and <9999999" << endl;
            return 1;
        }
        tmp = number;
        return 0;
    }
    void nameSetter(string userName) {
        name = userName;
        return;
    }
    void printDetailInfo() {
        cout << "Id:" << id << endl;
        cout << name;
    }
};

class Controller {
public:
    int ControllerIdSetter(Detail &object){
            object.id = object.tmp;
            return 0;
    }
};


int main()
{
    std::cout << "Enter a name of a detail\n";
    
    Detail object;
    
    string userName;
    
    cin >> userName;
    
    object.nameSetter(userName);
    object.printDetailInfo();
    
    Detail objects[3];
    Controller objControl;
    for (int i = 0; i < 3; i++) {
        cout <<endl <<"Enter the name of " << i + 1 << "detail" << endl;
        cin >> userName;
        objects[i].nameSetter(userName);
        cout << "Enter id of " << i + 1 << "detail (1000000 < x < 9999999)" << endl;
        int number;
        cin >> number;
        while (objects[i].idSetter(number) != 0) {
            cout << "Reenter ID: " << endl;
            cin >> number;
            objects[i].idSetter(number);
        }
        objControl.ControllerIdSetter(objects[i]);
        objects[i].printDetailInfo();
    }
}
