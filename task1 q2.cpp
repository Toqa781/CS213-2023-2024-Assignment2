//Q2
bool isPunctuation(char c) {
    return c == '.' || c == ',' || c == '?' || c == '!' || c == ';' || c == ':' || c == '-';
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    vector<string> words;
    string word = "";
    for (int i = 0; i < sentence.size(); i++) {
        if (sentence[i] == ' ' || isPunctuation(sentence[i])) {
            if (word != "") {
                words.push_back(word);
                word = "";
            }
            if (isPunctuation(sentence[i])) {
                words.push_back(string(1, sentence[i]));
            }
        } else {
            word += sentence[i];
        }
    }

    for (int i = 0; i < words.size(); i++) {
        if (words[i] == "he") {
            words[i] = "he or she";
        } else if (words[i] == "him") {
            words[i] = "him or her";
        } else if (words[i] == "his") {
            words[i] = "his or her";
        }else if (words[i] == "His") {
            words[i] = "His or Her";
        }else if (words[i] == "Him") {
            words[i] = "Him or Her";
        }else if (words[i] == "He") {
            words[i] = "He or She";
        }
    }

    string inclusive_speech = "";
    for (int i = 0; i < words.size(); i++) {
        inclusive_speech += words[i];
        if ( i != words.size()-1 && !isPunctuation(words[i + 1][0])) {
            inclusive_speech += " ";
        }
    }
    cout <<inclusive_speech;

}
