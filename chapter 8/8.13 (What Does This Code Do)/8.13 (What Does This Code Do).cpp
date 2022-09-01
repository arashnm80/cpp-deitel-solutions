// 8.13 (What Does This Code Do?)
// answer: It adds string2 to the end of string1
#include <iostream>
using namespace std;

void mystery1(char*, const char*); // prototype

int main() {
   char string1[80];
   char string2[80];

   cout << "Enter two strings: ";
   cin >> string1 >> string2;
   mystery1(string1, string2);
   cout << string1 << endl;

   // tip to understand mystery1 function(when '\0' is assigned to another variable it will return false):
   char a;
    char b{'m'};
    if(a = b){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    char c;
    char d{'\0'};
    if(c = d){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
}


void mystery1(char* s1, const char* s2) {
   while (*s1 != '\0') {
      ++s1;
   }

   for (; (*s1 = *s2); ++s1, ++s2) { // note: it is not equallity, it is assignment
      ; // empty statement
   }
}


