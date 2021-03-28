# mini_json project

/!\ Just a quick and dirty prototype of Json reader 

## Goals:
* Json reader prototype as simple and primitive as possible
* Inefficient (by design)
* DOES NO Json Schema validation

### Implementation rules
* Do not help the compiler:
    * avoid explicit inline
    * RVO & Copy elision are our friends: return by value is OK in most cases
    * Rules of five and rules of zero are our friends too
* No templates
* Stick to [YAGNI](https://en.wikipedia.org/wiki/You_aren%27t_gonna_need_it)
* _this_is_constant_ : use underscore for constant
* _mData_ : prefix 'm' + CamelCase for the data members

## Setup

## References
1. https://github.com/google/googletest/blob/master/googletest/README.md
2. https://github.com/kaizouman/gtest-cmake-example/
3. http://www.kaizou.org/2014/11/gtest-cmake.html
4. Effective Modern Cmake https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1
