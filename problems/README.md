Review: 
https://usaco.guide/bronze

Problems:
https://usaco.org/index.php?page=training

## useful tips

- 32 bits `int` can handle -2,147,483,648 to 2,147,483,647. i.e. 1e9 is ok

- Pipes in Bash are a way to connect the output of one command to the input of another.
    ```bash
    cd ~/Documents/USACO-Bronze/problems
    g++ -std=c++17 -O2 -lm -o myprogram.out Bronze202012P3.cpp

    cat ~/Downloads/prob3_bronze_dec20/2.in | ./myprogram.out
    cat ~/Downloads/prob3_bronze_dec20/2.in | ./myprogram.out | diff -u - ~/Downloads/prob3_bronze_dec20/2.out
    ```

- In Bash, moving the cursor: 
    `Option + arrow`: Moving by words.
    `Ctrl + a`: Moves the cursor to the beginning of the line.
    `Ctrl + e`: Moves the cursor to the end of the line.

- Run through all tests 1-10 provided with a Bash script
    ```bash
    cd ~/Documents/USACO-Bronze/problems
    g++ -std=c++17 -O2 -lm -o myprogram.out Bronze202012P3.cpp

    # chmod +x verify_results.sh
    ./verify_results.sh ~/Downloads/prob3_bronze_dec20
    ```

## progress log

2020-2021 Season
- 2025/06/01: https://usaco.org/index.php?page=dec20results
- 2025/06/08: https://usaco.org/index.php?page=jan21results
- 2025/06/15: https://usaco.org/index.php?page=feb21results
- 2025/06/22: https://usaco.org/index.php?page=open21results

2021-2022 Season
- 2025/06/29: https://usaco.org/index.php?page=dec21results
- 2025/07/06: https://usaco.org/index.php?page=jan22results
- 2025/07/13: https://usaco.org/index.php?page=feb22results
- 2025/07/20: https://usaco.org/index.php?page=open22results

2022-2023 Season
- 2025/07/27: https://usaco.org/index.php?page=dec22results
- 2025/08/03: https://usaco.org/index.php?page=jan23results

2023-2024 Season

2024-2025 Season


