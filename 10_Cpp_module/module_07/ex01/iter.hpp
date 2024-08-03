#ifndef ITER_HPP
#define ITER_HPP

// 함수 포인터 템플릿으로 정의해서 넘기기 ->  const 필요 없음
// template<typename T, typename Func>
// void iter(T *array, size_t length, Func func) {
//     for (size_t i = 0; i < length; i++) {
//         func(array[i]);
//     }
// }

template<typename T>
void iter(T *array, size_t length, void (*func)(T &)) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

template<typename T>
void iter(const T *array, size_t length, void (*func)(const T&)) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}


#endif