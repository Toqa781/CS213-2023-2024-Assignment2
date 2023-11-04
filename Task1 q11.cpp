// File: A2_S8_20220453_Q11.cpp
// Purpose: a file comparison facility that asks the user for the names of two files to compare
//          by character or by word
// Author: Farah Mohamed Magdy Mohamed
// Section: 8
// ID: 20220453
// TA: Khalid Ibrahim
// Date: 4 Nov 2023

void compare_byChar(string file1, string file2) {
    ifstream f1(file1);
    ifstream f2(file2);

    if (!f1 || !f2) {
        cout << "Error opening files" << endl;
        return;
    }

  vector<char> v1, v2;
  char c1,c2;
  int line = 1;
  bool diff = false;
  while (f1.get(c1)) {
    v1.push_back(c1);
  }
  while (f2.get(c2)) {
    v2.push_back(c2);
  }
  if (v1.size() != v2.size()) {
    diff = true;
  } else {
      for (int i = 0; i < v1.size(); i++) {
      if (v1[i] != v2[i]) {
        diff = true;
        c1= v1[i];
        c2=v2[i];
        break;
      }
      if (v1[i] == '\n') {
        line++;
      }
    }
  }
  if (diff == false) {
    cout << "The files are identical";
  } else {
    cout << "The files are not identical" << endl;
       cout << "First difference found on line " << line << endl;
       cout << "File 1: " << c1 << endl;
       cout << "File 2: " << c2 << endl;
  }
}

void compare_byWord(string file1, string file2) {
    ifstream f1(file1);
    ifstream f2(file2);

    if (!f1 || !f2) {
        cout << "Error opening files" << endl;
        return;
    }

   vector<string> v1, v2;
  string w1,w2;
  int line = 1;
  bool diff = false;
  while (f1 >> w1) {
    v1.push_back(w1);
  }
  while (f2 >> w2) {
    v2.push_back(w2);
  }
  if (v1.size() != v2.size()) {
    diff = true;
  } else {
    for (int i = 0; i < v1.size(); i++) {
      if (v1[i] != v2[i]) {
        diff = true;
        w1 = v1[i];
        w2 = v2[i];
        break;
      }
    }
  }

  if (diff == false) {
    cout << "The files are identical";
  } else {
      for (int i = 0; i < v1.size(); i++) {
      if (v1[i] == w1) {
        line = i + 1;
        return;
      }
       cout << "The files are not identical" << endl;
       cout << "First difference found on line " << line << endl;
       cout << "File 1: " << w1 << endl;
       cout << "File 2: " << w2 << endl;
       return;
    }
}

}
int main() {
    string file1, file2;
    int choice;

    cout << "Enter the name of the first file:" << endl;
    cin >> file1;
    cout << "Enter the name of the second file:" << endl;
    cin >> file2;

    cout << "Comparison by Character(1) or  by Word(2):" << endl;
    cin >> choice;

    if (choice == 1) {
        compare_byChar(file1, file2);
    } else if (choice == 2) {
        compare_byWord(file1, file2);
     }
}
