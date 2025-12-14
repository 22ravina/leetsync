

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int st0 = 0, st1 = 0;

    for (int i = 0; i < studentsSize; i++) {
        if (students[i] == 1) st1++;
        else st0++;
    }
    for (int i = 0; i < sandwichesSize; i++) {
        if (sandwiches[i] == 1) {
            if (st1 > 0){
                st1--;
            }else{
                break;
            }
        } else {
            if (st0 > 0){
                st0--;
            }else {
                break;
            }
        }
    }

    return st0 + st1;



    
}