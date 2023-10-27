#include <iostream>
using namespace std;

int main()
{
    char s[200];
    int i=0, j;
    bool flag = false;
    gets(s);
    while(s[i]!='\0')
    {
        flag = false;
        if(s[i]==' ' && s[i+1]==' ')
        {
            for(j=i; s[j-1]!='\0'; j++)
                s[j] = s[j+1];
            flag = 1;
        }
        if( i == 0 || (i > 0 && s[i-1]== '.') ) {
            s[i] = toupper(s[i]);
        }
        else s[i] = tolower(s[i]);
        if(!flag)
            i++;
    }
    cout<<s<<endl;
    return 0;
}
