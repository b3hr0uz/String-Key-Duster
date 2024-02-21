//
//  main.cpp
//  String-Key-Duster
//
//  Created by Behrouz Barati on 8/24/21.
//

#include <iostream>
#include <fstream>
#include <string>
//#include <bits/stdc++.h>
#include <chrono>
#include <sys/time.h>

using namespace std;

int countDigits(string(str)) {
    string st = str;
    int count = 0;
    for(int i = 0; i < st.size(); i++)
        if(isdigit(st[i])) count++;
    return count;
}

bool charFrequency(string(str)) {
    string st = str;
    int charPointer = 0;
    int count = 0;
    bool flag = false;
    char checkCharacter = st[charPointer];
    while(checkCharacter) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] ==  checkCharacter) ++ count;
        }
//      if(charPointer != 0) cout << checkCharacter << " : " << count << endl;
        if(count >= 5) flag = true;
        checkCharacter = st[charPointer++];
        count = 0;
    }
    return flag;
}

bool QuadChar(string(str)) {
    string st = str;
    char alpha, beta, gamma, delta;
    bool flag = false;
    if(st.size() < 4) return flag;
    for(int i = 0; i < st.size() - 3; i++) {
        alpha = st[i]; beta = st[i + 1]; gamma = st[i + 2]; delta = st[i + 3];
        if ((alpha == beta) && (beta == gamma) && (gamma == delta)) flag = true;
    }
    return flag;
}

int main() {
     auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    ifstream file("input.txt");
    ofstream fileout("output.txt");
    ifstream refrence("reference.txt");
    string str, refstr;
    bool flag = false;
    while(getline(file, str)) {
        if(countDigits(str) < 9) {
            if(!QuadChar(str)) {
                charFrequency(str);
                if(!charFrequency(str)) {
                    while(getline(refrence, refstr)) {
                        flag = false;
                        if(str == refstr) {
                            flag = true;
                            break;
                        }
                    }
                transform(str.begin(), str.end(),str.begin(), ::toupper);
                if(!flag) fileout << str << endl;
                refrence.clear();
                refrence.seekg(0, refrence.beg);
                }
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    system("pause");
    return 0;
}
