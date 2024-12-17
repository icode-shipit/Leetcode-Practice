bool isCircularSentence(char* sentence) {
    char b[strlen(sentence)];
    int j = strlen(sentence);
    sentence[j] = '\0';
    int count = 0;
    for (int i = 0; i < j + 1; i++) {
        if (sentence[i] == ' ') {
            if (sentence[i - 1] == sentence[i + 1]) {
                b[count] = 1;
                count++;
            } else {
                b[count] = 0;
                count++;
            }
        }
        if (sentence[i] == '\0') {
            if (sentence[0] == sentence[j - 1]) {
                b[count] = 1;
                count++;
            } else {
                b[count] = 0;
                count++;
            }
        }
    }
    if (count == 1) {
        if (b[count-1] == 1) {
            return true;
        } else if (b[count-1] == 0) {
            return false;
        }
    } else {
        for (int i = 0; i < count; i++) {
            if (b[i] == 0) {
                return false;
            }
        }
        return true;
    }
    return 0;
}

