Calculate solutions of congruence equation Ax ≡ B (mod M)

# Build
You can build the program with [Meson](https://mesonbuild.com/). First, setup the project with the command:
```
$ meson setup builddir
$ cd builddir
```
Then, compile it with:
```
$ meson compile
```
Also, you can install it if you want:
```
$ meson install
```

# Usage
A congruence equation is composed by 3 elements: A, B and M.
They correspond to the equation: Ax ≡ B (mod M).

So this program is use like this:

`$ congruence A B M N`

'N' is the number of solutions you want to get, so for example, if you want 5 solutions of 34x ≡ 5 (mod 53), the command will be:

`$ congruence 34 5 53 5`

The output is:
```
Solutions of 34x = 5 (mod 53) :
-70
-17
36
89
142
```
