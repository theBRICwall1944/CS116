#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split_sentence(string sentence){

    stringstream ss(sentence);

    string word;
    
    vector<string> words;

    while (ss >> word){

        words.push_back(word);

    }

    return words;
}
int main(){
    string sentence;

    cout << "please enter a sentence" << endl;

    cin >> sentence;

    vector<string> words = split_sentence(sentence);

    for (string w : words){

        cout << w << endl;
    }

    return 0;
}