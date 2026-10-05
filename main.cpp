#include <iostream>
#include <fstream>
#include <format>
#include <clocale>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
// task4.1
int main() {
    int choice=-1;
    while(choice != 0) {
        fs::path currentPath=fs::current_path();
        cout << std::format("Potochnui katalog: {}\n", currentPath.string());
        cout<<"1-Zmina potochnogo katalogy\n";
        cout<<"2-Pokazatu vsi pidkatalogy\n";
        cout<<"3-Vidobrqzutu vsi file\n";
        cout<<"4-Stvorutu novui katalog\n";
        cout<<"5-Vudalutu ketelog\n";
        cout<<"0-Exit\n";
        cout<<"enter choice ";
        cin>>choice;
        if (choice == 1) {
            cout<<"Enter new shlah:";
            string newPathstr;
            cin>>newPathstr;
            fs::path newPath(newPathstr);
            if (exists(newPath) && is_directory(newPath)) {
                current_path(newPath);
                cout<<"Katalog zineno";
            }
            else {
                cout<<"Kataloga ne isnue";
            }
        }
        else if (choice == 2) {
            cout<<"Pidkatalogi\n";
            bool found=false;
            for (const auto& entry : fs::directory_iterator(currentPath)) {
                if (entry.is_directory()) {
                    cout<<"[DIR] "<<entry.path().filename().string()<<"\n";
                    found=true;
                }
            }
            if (!found) {
                cout<<"(pidkatalogi vidsutni)\n";
            }
        }
        else if (choice == 3) {
            cout<<"File\n";
            bool found=false;
            for (const auto& entry : fs::directory_iterator(currentPath)) {
                if (entry.is_regular_file()) {
                    cout<<"[FILE] "<<entry.path().filename().string()<<"\n";
                    found=true;
                }
            }
        }
    }
}