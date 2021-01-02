#include <iostream>
#include <string>

using namespace std;

int getRandom(int min, int max) {
//    return rand() % max % (max - min + 1) + min;
    return rand() % (max - min + 1) + min;
}

void shuffle(string& str) {
    for (int i = str.size() - 1; i >= 0; i--) {
        int j = rand() % (i + 1);
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

int main() {
    struct timeb timer;
    ftime(&timer);
    srand(timer.time * 1000 + timer.millitm);//毫秒种子

    string upper, lower, number, symbol;
    for (int i = 33; i < 127; i++) {
        if (i >= '0' && i <= '9')
            number += char(i);
        else if (i >= 'a' && i <= 'z')
            lower += char(i);
        else if (i >= 'A' && i <= 'Z')
            upper += char(i);
        else
            symbol += char(i);
    }

    shuffle(upper);
    shuffle(lower);
    shuffle(number);
    shuffle(symbol);

    int upperNum = getRandom(4, 6);
    int lowerNum = getRandom(4, 6);
    int numNum = getRandom(4, 4);
    int symbolNum = getRandom(4, 6);

    string res;
    for (int i = 0; i < upperNum; i++) {
        int j = rand() % upper.size();
        res.push_back(upper[j]);
    }
    for (int i = 0; i < lowerNum; i++) {
        int j = rand() % lower.size();
        res.push_back(lower[j]);
    }
    for (int i = 0; i < numNum; i++) {
        int j = rand() % number.size();
        res.push_back(number[j]);
    }
    for (int i = 0; i < symbolNum; i++) {
        int j = rand() % symbol.size();
        res.push_back(symbol[j]);
    }
    shuffle(res);
    cout << res << endl;
    return 0;
}
