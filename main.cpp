
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string keyword []= {"int", "float", "char", "double",
    "if", "else", "while", "for",
    "return", "void"};

  string myText;

  ifstream MyReadFile("abrar4.txt");

    char ch;
    string word = "";

    while (MyReadFile.get(ch))
    {

        if ((ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') || ch == '_' || (ch >= '0' && ch <= '9') ||
           (word.length() > 0 && ch == '.' && word[0] >= '0' && word[0] <= '9'))
        {
           word = word + ch;
        }

        else
        {
            if (word != "")
            {
                //cout << "DEBUG: [" << word << "]" << endl;
                bool found = false;

                for (int i = 0; i < 10; i++)
                {
                    if (word == keyword[i])
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                    cout << word << " : Keyword" << endl;

                    else if (word[0] >= '0' && word[0] <= '9')
                    cout << word << " : Constant" << endl;
                else
                    cout << word << " : Identifier" << endl;

                word = "";
            }

            if (ch == '+' || ch == '-' || ch == '*' ||
                ch == '/' || ch == '=' || ch == '<' ||
                ch == '>')
                cout << ch << " : Operator" << endl;

            else if (ch == '(' || ch == ')' ||
                     ch == '{' || ch == '}' || ch == ';' ||
                     ch == ',')
                cout << ch << " : Separator" << endl;
        }
    }

    if (word != "")
    {  //cout << "DEBUG: [" << word << "]" << endl;
        bool found = false;

        for (int i = 0; i < 10; i++)
        {
            if (word == keyword[i])
            {
                found = true;
                break;
            }
        }

        if (found)
            cout << word << " : Keyword" << endl;

            else if (word[0] >= '0' && word[0] <= '9')
            cout << word << " : Constant" << endl;

        else
            cout << word << " : Identifier" << endl;
    }


  while (getline (MyReadFile, myText)) {
    cout << myText<<endl;
  }

  MyReadFile.close();


    return 0;
}

