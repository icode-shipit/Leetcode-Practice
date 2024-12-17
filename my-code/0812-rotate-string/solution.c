char* rotateStringCheck(char* s);
bool rotateString(char* s, char* goal) {
    int p = strlen(s);
    
    if (p != strlen(goal)) {
        return false;  
    }

    for (int i = 0; i < p; i++) {
        if (strcmp(s, goal) == 0) {
            return true;
        }
        rotateStringCheck(s);
    }

    return false;
}

char* rotateStringCheck(char* s) {
    int p = strlen(s);
    char firstChar = s[0];  
    for (int i = 0; i < p - 1; i++) {
        s[i] = s[i + 1];
    }
    s[p - 1] = firstChar;
    
    return s;  
}

