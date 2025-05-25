# USACO-Bronze

https://usaco.org/

Bronze, for students who have recently learned to program, but who have no training in algorithms beyond basic concepts like sorting and binary search.

Each contest has typically 3 or 4 problems to which you will submit solution programs in C, C++, Java, or Python. C++ is the only language supported at IOI, this is the clear answer once you reach higher levels.

Contest are typically 4..5 contiguous hours in length. You can take the contest during any block of time you want within the larger contest window. When you start the contest, your personal timer starts counting down

When you submit a program, it will be run against a number of judging test cases and for each one, you will receive feedback, shown in a colored box: green for correct, and red for incorrect. Incorrect submissions are further differentiated by the type of problem: X (incorrect answer), T (time limit exceeded), ! (run-time error or memory limit exceeded), E (empty output file), or M (missing output file). If your program fails to compile, you will be shown the error messages from the compiler. 

## UNIX and language settings

Since this is a UNIX environment, lines in all input/output files are terminated with a single newline "\n", rather than a carriage return plus newline "\r\n"

Note that as of the December 2020 contest, input and output switched from file-based to terminal-based, using standard input and standard output (e.g., cin and cout in C++). The input and output spec of a problem will specify which mode is being used. For C++ users, you may want to add "ios_base::sync_with_stdio(false); cin.tie(0);" to the top of your main method if you are using cin/cout.

For C/C++ programmers: Programs are compiled with gcc/g++ 7.5.0 using the "-O2" optimization flag and "-lm" to access the math library, and "-std=c++11" or "-std=c++17" to enable support for C++11 or C++17. Ints are 32 bits in size; use a "long long" if you need a 64-bit integer. To read or write a long long variable with C-style I/O (e.g., scanf, printf), use the "%lld" format string.

### Basic Linux Commands for C++

Here are some simple Linux commands useful for C++ programming:

- **Show the current directory:**
    ```bash
    pwd
    ```

- **List files in the current directory:**
    ```bash
    ls -l
    ```

- **Change directory:**
    ```bash
    cd foldername
    cd ../at_parent_level
    ```

- **Print the contents of a file to the screen:**
    ```bash
    more myprogram.cpp
    ```

- **Run the compiled program:**
    ```bash
    ./myprogram
    ```

If you try to run a program in the current directory with just its name (e.g., myprogram), the shell may not find it unless `.` is in your PATH. That's why you often use `./myprogram` to run executables in the current directory.

- **Check if a file is executable:**
    ```bash
    ls -l myprogram
    ```
If you see an `x` in the permissions (e.g., `-rwxr-xr-x`), the file is executable. If not, add execute permission with:
    ```
    chmod +x myprogram
    ```

### Quitting a Running Program

To quit a running program in the terminal, you can usually press `Ctrl+C`. This sends an interrupt signal (SIGINT) to the program, causing it to terminate.

If you are running a text editor like `vim`:
- In `vim`, press `Esc`, then type `:q` and press `Enter` to quit (use `:q!` to force quit without saving).

If a program does not respond to `Ctrl+C`, you can find its process ID (PID) using `ps` or `top`, and then use `kill PID` to terminate it.
