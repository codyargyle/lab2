#ifndef OUR_MAP_H
// User passes in two data structures of type int (like an array) by reference
// The user will also give a function that will allow them to do an operation 
// on said elements and length that will apply the function on them from
// 0 to specficed length - 1
void map(int* input_list, int* output_list, int length, int (*func)(int)){
    for(int i = 0; i < length; i++){
        *(output_list + i) = func(*(input_list+i));
    }
}
#endif