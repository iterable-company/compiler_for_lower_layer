#!/bin/bash
assert() {
    expected="$1"
    input="$2"

    ./9cc "$input" > tmp.s
    cc -o tmp tmp.s
    ./tmp
    actual="$?"

    if [ "$actual" = "$expected" ]; then
        echo "$input => $actual"
    else
        echo "$input => $expected expected, but got $actual"
        exit 1
    fi
}

assert 0 "0;"
assert 42 "42;"
assert 15 "10-2+7;"
assert 91 "100 - 2 -7;"
assert 17 "1*2 + 3*5;"
assert 246 "-2*+5;"  # 246 = -10 + 2^8
assert 1 "2==2;"
assert 0 "2==3;"
assert 1 "2!=3;"
assert 0 "2!=2;"
assert 1 "2<3;"
assert 0 "2<1;"
assert 1 "2<=2;"
assert 1 "2<=3;"
assert 0 "2<=1;"
assert 1 "2>1;"
assert 0 "2>3;"
assert 1 "2>=2;"
assert 1 "2>=1;"
assert 0 "2>=3;"
assert 1 "(1+3)==(2*2);"
assert 0 "(1+3)==(2*2+1);"
assert 3 "a=1;b=2;a+b;"
assert 5 "a=1;g=4;a+g;"
assert 5 "abc=4;gh=3;abc+abc-gh;"
assert 7 "abc=4;gh=3;return abc + gh;4;"

echo OK