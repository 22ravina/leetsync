void reverseString(char* s, int sSize) {
    char *temp = malloc(sSize);
    memcpy(temp,s,sSize);

    for(int i=0;i<sSize;i++){
        s[i] = temp[sSize-i-1];
    }
    free(temp);
    
}