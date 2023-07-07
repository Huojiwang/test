#include<iostream>
// using namespace std;

// using co_context::generator
struct fib_frame{
    int a;
    int b;
    int c;
    int state;
};

int fib(fib_frame &f){
    switch (f.state)
    {
    case /* constant-expression */ 0 :
        f.state = 1;
        goto s0;
    case 1:
        f.state = 2;
        goto s1;
    case 2:
        f.state = 3;
        goto s2;
    case 3:
        goto s3;
s0:
    f.a = f.b = 1;
    return f.a;
s1:
    return f.b;
s2:
    for(;;)
    {
        /* code */
        f.c = f.a + f.b;
        return f.c;
    s3:
        f.a = f.b;
        f.b = f.c;
    }
    }
}
int main(){
    using std::cout,std::endl;
    fib_frame f;
    for(int i = 0; i < 10;++i){
        int x = fib(f);
        cout<<x<<endl;
    }
}