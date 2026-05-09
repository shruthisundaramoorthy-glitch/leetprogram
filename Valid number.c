#include <stdbool.h>

bool isNumber(char* s) {

    int i = 0;

    bool seenDigit = false;
    bool seenDot = false;
    bool seenExp = false;

   
    while(s[i] == ' ')
        i++;

    for(; s[i] != '\0'; i++) {

        char c = s[i];

        if(c >= '0' && c <= '9') {

            seenDigit = true;
        }

        else if(c == '+' || c == '-') {

           
            if(i > 0 &&
               s[i-1] != 'e' &&
               s[i-1] != 'E' &&
               s[i-1] != ' ')
                return false;
        }

        else if(c == '.') {

           
            if(seenDot || seenExp)
                return false;

            seenDot = true;
        }

        else if(c == 'e' || c == 'E') {

            
            if(seenExp || !seenDigit)
                return false;

            seenExp = true;

            seenDigit = false;
        }

        else if(c == ' ') {

            
            while(s[i] == ' ')
                i++;

            return s[i] == '\0';
        }

        else {

            return false;
        }
    }

    return seenDigit;
}