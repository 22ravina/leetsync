int countConsistentStrings(char * allowed, char ** words, int wordsSize) {
    int freq[26] = {0};
    int count =0;
    int n1 = strlen(allowed);
    for(int i=0;i<n1;i++){
        freq[allowed[i]-'a'] =1;
    }

    for(int i=0;i<wordsSize;i++){
        int ok =1;
        int n2 = strlen(words[i]);
        for(int j=0;j<n2;j++){
            if(freq[words[i][j]-'a']==0){
                ok =0;
                break;
            }
        }
        if(ok==1){
            count++;
        }
    }
    return count;
}
