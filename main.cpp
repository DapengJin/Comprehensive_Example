#include <fstream>
#include <sstream>
//#include "Array.h"
#include "Controller.h"
#include "AccountException.h"

using namespace std;

int main() {
    Date date(2008, 11, 1); // 起始日期
    Controller controller(date);
    char cmd;
    string space = " ";
    string cmdLine;
    const char *FILE_NAME = "commands.txt";
    ifstream fileIn(FILE_NAME); // 用“读”模式打开文件
    if(fileIn){ // 正常打开
        while (getline(fileIn, cmdLine)){
            try{
                controller.runCommand(cmdLine);
            } catch (exception &e) {
                cout << "Bad line in " << FILE_NAME << ": " << cmdLine << endl;
                cout << "Error: " << e.what() << endl;
                return 1;
            }

        }
        fileIn.close();
    }



    ofstream fileOut(FILE_NAME, ios_base::app);
    bool if_get_new_line;
    while(! controller.isEnd()){
        cout << "\n" << endl;
        cout << controller.getDate();
        cout << "--------------------------------------------------------------------------------------" ;
        cout << "Total: " << Account::getTotal() << endl;
        cout << "(a) add an account, (d) deposit, (w) withdraw, (s) show, (c) change day, (n) next month, (q) query, (e) exit" << "\ncommand>_";
        cin >> cmd;

        if_get_new_line = true;
        cmdLine = "";
        switch (cmd) {

            case 'a': // 增加新账户
                cout << "add a new account: \ntype:'s'  id:string  rate: double\ntype:'c'  id:string  credit, rate, fee: double" << "\n\tcommand>_" ;
                break;
            case 'd':
                cout << "deposit: index:int  amount:double desc: string \n\tcommand>_" ;
                break;
            case 'w':
                cout << "withdraw: index:int  amount:double desc: string \n\tcommand>_";
                break;
            case 'c':
                cout << "change day: day:int \n\tcommand>_";
                break;
            case 'q': // 查询一段时间的账目
                cout << "query records for some time range: start/end date: year-month-day" << "\n\tcommand>_" ;
                break;
            default:
                if_get_new_line = false;
        }

        if (if_get_new_line){
            cin.ignore();
            getline(cin, cmdLine, '\n');
        }


        ostringstream oss;
        oss << cmd << ' ' << cmdLine;
        try{
            if (controller.runCommand(oss.str())){
                fileOut << oss.str() << endl;
            }
        }catch (AccountException &e){
            cout << "Error(#" << e.getAccount()->getId() << "): " << e.what() << endl;
        } catch (exception &e) {
            cout << "Error:" << e.what() << endl;
        }

    }
    fileOut.close();
    return 0;
}
