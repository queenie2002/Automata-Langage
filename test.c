void main(void) {
    int a = 2;
    if (a == 0) {
        a = 6;
    }
    else if (a==2){
        a = 3;
        if (a==3) {
            a = 7;
        }

    }
    print(a);
}