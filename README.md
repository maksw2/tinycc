# c without semicolons

have you ever wondered how cursed c would look without semicolons?

## how 2 compile

- `cd win32`
- `build-tcc.bat`

idk about linux figure it out yourself go to the original repo https://github.com/TinyCC/tinycc

## how 2 use

- `vim test.c`
- `tcc test.c`
- `test.exe`

## where it breaks (Here be Dragons)

1.
source code:
```c
a = b
(c) = d
```
compiler sees:
```c
a = b(c) = d;
```

2.
source code:
```c
x = y
-z
```
compiler sees:
```c
x = y - z;
```

3.
source code:
```c
val = ptr1
*ptr2 = 10
```
compiler sees:
```c
val = ptr1 * ptr2 = 10;
```

## q&a

Q: Why does this exist?
A: I suffer from an incurable disease called too much free time.

Q: How does it work?
A: `-skip(';');` `+if (tok == ';') skip(';');` and some struct tomfoolery.

Q: Can i use this in production?
A: Why would you?
