#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int wordCount(){

    return 0;
}


int uniqueC(string sentence) {
    int cCount = 0;
    vector<char> charlist;

    for (int i = 0; i < sentence.size(); i++){

        if (!isalpha(sentence[i])) continue;
        bool dub = false;
        char lowerChar = tolower(sentence[i]);

        for (int j = 0; j < charlist.size(); j++){
            if (charlist[j] == lowerChar) {
                dub = true;
                break;
            }
        }

        if (!dub){
            charlist.push_back(lowerChar);
            cCount++;
        }
    }

    return cCount;
}

int longestWrd(vector<string> words){
    int longestWrd = 0;
    int currentLength;

    for (int i = 0; i <  words.size(); i++){
        currentLength = words[i].size();

        if (currentLength > longestWrd) {
            longestWrd = currentLength;
        }
    }
    return longestWrd;
}

int mostVowel(vector<string> words){
    int mostVowel = 0;

    for (int i = 0; i < words.size(); i++){
        int currentVowel = 0;
        string currentWord = words[i];

        for (int j = 0; j < currentWord.size(); j++){
            if (!isalpha(currentWord[j])) continue;

                
            switch (tolower(currentWord[j])) {
                case 'a':
                case 'e':
                case 'i':   
                case 'o':
                case 'u':
                    currentVowel++;

                
            }
            
            if (currentVowel > mostVowel){
                mostVowel = currentVowel;
            }
        }
    }

    return mostVowel;
}

int main(){
    string sentence;

    getline(cin, sentence);

    vector<string> wordList;

    wordList.push_back(string{});

    for (int i = 0; i < sentence.size(); i++) {
        
        if (sentence[i] == ' '){
            wordList.push_back(string{});
            continue;
        }

        wordList.back().push_back(sentence[i]);
    }

    cout << wordList.size() << " ";
    cout << uniqueC(sentence) << " ";
    cout << longestWrd(wordList) << " ";
    cout << mostVowel(wordList);

    return 0;
}