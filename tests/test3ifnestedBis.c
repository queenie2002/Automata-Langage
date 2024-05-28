//marche pas
void main(void) {
    int a = 0;
    int b = 1;
    if (a) {
        a = 6;
        if(b){
            a=9;
            print(a);
            b=5;
        } 
        a = 7;
    }
    print(a);
    print(b);
}