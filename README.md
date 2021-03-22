# mini_json

/!\ Just a quick and dirty protptype 

## Goals:
* Json reader protptype as simple and primitive as possible
* Inefficient (by design)

### Implementation rules
* Do not help the compiler:
    * avoid explicit inline
    * RVO & Copy elision are our friends: eturn by value is OK in most cases
    * Rules of five and rules of zero are our friends too
* No templates
* Stick to [YAGNI!](https://en.wikipedia.org/wiki/You_aren%27t_gonna_need_it)
* _this_isconstant_ use underscore for constant
* _mData_ prefix 'm' + camel case for the data members
