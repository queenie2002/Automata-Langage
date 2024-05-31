void main(void) {
    //identifiers format

    //add/sub/div/mul/and or not/<> etc

    //if nested avec id ou condition
    //if else, else if

    //scope 

    //while


    int a, d=0;
    int b=6,c=8/2;

    b = 6;
    c=8/2;
    a = b + c * 2;
    print(a);
    //should print 14

    if (d == 0) {
        d = 1;
        print(d); //should print 1

        if(d<5+1 || 3<5){
            int e=9;
            print(e); //should print 9
        } 

    }

    if (d==2) {
        //nothing
    } else {
        print(d); //should print 1
    }

    if (d==2) {
    } else if (d==1) {
        print(b); //should print 6
    }

    while(d<a) {
        d= d + 1; 
    }
    print(d); //should print 14
    //print(e); //should cause a problem of scope
    
}