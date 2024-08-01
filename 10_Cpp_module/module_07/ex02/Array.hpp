#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
    private:
        T *_arr;
        unsigned int _size;
        unsigned int _capacity;

    public:
        Array() : _arr(NULL), _size(0), _capacity(0) {};

        Array(unsigned int n) : _arr(NULL), _size(n), _capacity(n) {
            if (n > 0) {
                _arr = new T[n];
            }
        };

        Array(const Array &src) : _arr(NULL), _size(src._size), _capacity(src._size) {
            if (src._size > 0) {
                _arr = new T[src._size];
                for (unsigned int i = 0; i < _size; i++) {
                    _arr[i] = src._arr[i];
                }
            }
        };

        Array &operator=(const Array &src) {
            if (this == &src) {
                return *this;
            }
            _size = src._size;
            _capacity = src._size;

            delete[] _arr;
            if (src._size > 0) {
                _arr = new T[src._size];
                for (unsigned int i = 0; i < _size; i++) {
                    _arr[i] = src._arr[i];
                }
            }
            return *this;
        };

        ~Array() {
            delete[] _arr;
        };

        unsigned int size() {
            return _size;
        };


        T& operator[](unsigned int idx) {
            if (idx < 0 || idx > this->_size - 1)
                throw std::out_of_range("Index out of range");
            return this->_arr[idx];
        }

        const T& operator[](unsigned int idx) const {
            if (idx < 0 || idx > this->_size - 1)
                throw std::out_of_range("Index out of range");
            return this->_arr[idx];
        }
};

#endif