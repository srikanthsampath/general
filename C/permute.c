#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void swap(char *str, int from, int to) {
    char temp = *(str + from); 
    *(str + from) = *(str + to);
    *(str + to) = temp;
}

/*
* Recursively call permute. Key is that you keep
* switching the characters with "begin" till" end
* and call it recursively.  Once you end the recursion
* flip back - backtrack that's key.
* Running time: n!
*/
void permute(char *s, int begin, int end) {
    if (begin == end) {
        printf("STRING: %s\n", s); 
    } else {
        for (int i = begin; i <= end; i++) {
            swap(s, begin, i);
            permute(s, begin+1, end);
            swap(s, i, begin);
        }
    }   
}



int main(int argc, char* argv[]) {

    char *input = argv[1];
    int length = strlen(input);

    permute(input, 0, (length -1));

}




