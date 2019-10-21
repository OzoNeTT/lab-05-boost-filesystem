#pragma once

#include <boost/filesystem.hpp>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <boost/regex.hpp>
#include <vector>

using namespace boost::filesystem;
using namespace std;


//будем хранить так - map<брокер, аккаунт - map< кол-во файлов, последний день>>
map<string, map<int, pair<int, int>>> brokers;

void fileFind(string path, size_t skipSubstr) {
    for (const directory_entry &x : directory_iterator(path)){
        if (is_directory(x.path()))
            fileFind(x.path().string(), skipSubstr);
        else{
            string fileName = x.path().filename().string();
            int _num1, _num2;
            try{
                if (fileName.find("balance_") != 0)
                    continue;
                if (fileName[16] != '_')
                    continue;
                _num1 = stoi(fileName.substr(8, 8));
                _num2 = stoi(fileName.substr(17, 8));
                if (fileName.substr(25) != ".txt")
                    continue;
                cout << path.substr(skipSubstr) << ' ' << fileName << endl;
                string broker = path.substr(skipSubstr);
                brokers[broker][_num1].first++;
                brokers[broker][_num1].second = std::max(brokers[broker][_num1].second, _num2);
            }
            catch (exception &e){
                continue;
            }
        }
    }

}

void FileGet () {
    for (const auto &x : brokers){
        for (const auto &y : x.second){
            cout << "broker:" << x.first << " account:" << y.first << " files:" << y.second.first
                 << " lastdate:" << y.second.second << endl;
        }
    }
}