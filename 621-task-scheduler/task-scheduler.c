int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};

    // Count frequencies
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Find max frequency
    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    // Count number of tasks having max frequency
    int maxCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq)
            maxCount++;
    }

    // Formula
    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int emptySlots = partCount * partLength + maxCount;

    // Result must be at least tasksSize
    int result;
    if (emptySlots > tasksSize) {
        result = emptySlots;
    } else {
        result = tasksSize;
    }

    
return result;


    
}