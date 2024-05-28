//marche pas a cause de if nested
void main(void) {
    int a = 0;
    if (a == 0) {
        int b=2;
        if(b == 0){
            int c=3;
            print(a);
            print(b);
            print(c);
        } 
    }
}