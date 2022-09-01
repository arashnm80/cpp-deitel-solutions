template <typename T>
T power(T base, unsigned exponent){
    if(0 == exponent){
        return 1;
    }else{
        return base * power(base, exponent - 1);
    }
}