char* predictPartyVictory(char* senate) {
    int n = strlen(senate);

    int rq[10000], dq[10000];
    int rf = 0, rr = 0;
    int df = 0, dr = 0;

    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R')
            rq[rr++] = i;
        else
            dq[dr++] = i;
    }

    while (rf < rr && df < dr) {
        int r = rq[rf++];
        int d = dq[df++];

        if (r < d)
            rq[rr++] = r + n;  // Radiant bans Dire
        else
            dq[dr++] = d + n;  // Dire bans Radiant
    }

    return (rf < rr) ? "Radiant" : "Dire";
}
