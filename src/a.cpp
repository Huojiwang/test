#include<iostream>
#include<exception>
// using namespace std;

// using co_context::generator
struct fib_frame{
    bool ready = true;
    std::exception_ptr exception;
    int a;
    int b;
    int c;
    int state;
    int param;

    fib_frame(int para):param(para){}
    int resume(){
        try{

            switch (state)
            {
            case /* constant-expression */ 0 :
                state = 1;
                goto s0;
            case 1:
                state = 2;
                goto s1;
            case 2:
                state = 3;
                goto s2;
            case 3:
                goto s3;
            }
        s0:
            a = b = 1;
            return a;
        s1:
            return b;
        s2:
            for(;;){
                    /* code */
                    c = a + b;
                    return c;
                s3:
                    a = b;
                    b = c;
            }
        }catch (...) {
            this->exception = std::current_exception();
        }
    }
};
int main(){
    using std::cout,std::endl;
    fib_frame fib(3);
    for(int i = 0; i < 10;++i){
        int x = fib.resume();
        cout<<x<<endl;
    }
}