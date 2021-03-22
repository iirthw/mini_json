# mini_json project

/!\ Just a quick and dirty prototype of Json reader 

## Goals:
* Json reader prototype as simple and primitive as possible
* Inefficient (by design)

### Implementation rules
* Do not help the compiler:
    * avoid explicit inline
    * RVO & Copy elision are our friends: return by value is OK in most cases
    * Rules of five and rules of zero are our friends too
* No templates
* Stick to [YAGNI](https://en.wikipedia.org/wiki/You_aren%27t_gonna_need_it)
* _this_is_constant_ : use underscore for constant
* _mData_ : prefix 'm' + CamelCase for the data members
