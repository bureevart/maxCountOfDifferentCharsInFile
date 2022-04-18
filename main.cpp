#include <iostream>

#include <fstream>/*ifstream ofstream*/
#include <string.h>

using namespace std;

/**
 *  Открытие нового файла
 *
 * @param name имя файла
 * @return открытый файл
 */
bool openFile(string name, fstream* file) {
    (*file).open(name + ".txt");

    if (!(*file).is_open()) {
        return false;
    }
    return true;
}

/**
 * Поиск различных элементов в файле
 *
 * @param file1 первый файл
 */
void maxCountOfDifferentCharsInFile(fstream* file1) {
    int maxCount = 0;
    int tempCount;
    char ch;
    char lastCh;

    while ((*file1).get(ch)){
        if(tempCount == 0 || lastCh != ch) {
            lastCh = ch;
            tempCount++;
        } else {
            if(maxCount < tempCount) {
                maxCount = tempCount;
            }

            tempCount = 0;
        }

    }
    cout << "Максимальное количество различных элементов идущих подряд: " << maxCount << endl;
}

int main() {
    system("chcp 1251>nul");

    string name;
    fstream firstFile;

    cout << "Введите имя первого файла: ";
    cin >> name;

    if(!openFile(name, &firstFile)) {
        cout << "Файл не открылся!";
        return 0;
    }

    maxCountOfDifferentCharsInFile(&firstFile);

    firstFile.close();

    return 0;
}
