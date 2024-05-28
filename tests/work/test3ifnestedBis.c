void main(void) {
    int a = 1;
    int b = 1;
    if (a) {
        a = 6;
        print(a);

        if(b){
            a=9;
            b=5;
            print(a);
            print(b);
        } 
        a = 7;
    }
    print(a);
    print(b);
}