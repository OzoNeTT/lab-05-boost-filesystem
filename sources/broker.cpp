#include "broker.hpp"

int main(int argc, char **argv){
    string path_to_ftp;
    if (argc == 2){
        path_to_ftp = string(argv[1]);
    }
    else{
        path_to_ftp = "../";
    }
    fileFind(path_to_ftp, path_to_ftp.length() + 1);
    for (const auto &x : brokers){
        for (const auto &y : x.second){
            cout << "broker:" << x.first << " account:" << y.first << " files:" << y.second.first
                 << " lastdate:" << y.second.second << endl;
        }
    }
}