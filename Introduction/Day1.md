Learning essential CLI tools in Linux: ls, grep, awk, sed, and strace. These tools are fundamental for navigating, manipulating, and debugging in a Linux environment. Let’s break it down step by step
I am going to delete this line.
1. ls – List Files and Directories
    Purpose: List files and directories in the current or specified directory.

    Common Options:
    ls: List files and directories in the current directory.

    ls -l: Long listing format (shows permissions, owner, size, etc.).

    ls -a: Show hidden files (files starting with .).

    ls -h: Human-readable file sizes (e.g., KB, MB).

    ls -R: Recursively list subdirectories.

    Examples:
    bash
    
    ls                  # List files in the current directory
    ls -l /home         # Long list of files in /home
    ls -a ~             # List all files (including hidden) in the home directory

2. grep – Search Text
    Purpose: Search for patterns in files or output.

    Common Options:
    grep "pattern" file: Search for a pattern in a file.

    grep -i: Case-insensitive search.

    grep -r: Recursively search in directories.

    grep -v: Invert match (show lines that do not match the pattern).

    grep -E: Use extended regular expressions.

    Examples:
    bash
    
    grep "error" log.txt          # Search for "error" in log.txt
    grep -i "warning" log.txt     # Case-insensitive search for "warning"
    grep -r "main" /home/user     # Recursively search for "main" in /home/user
    ps aux | grep "chrome"        # Find all processes containing "chrome"

3. awk – Text Processing
    Purpose: Process and analyze text files or output.

    Basic Syntax:
    bash
    
    awk 'pattern { action }' file
    Common Uses:
    Print specific columns: awk '{print $1, $3}' file.

    Filter rows based on a condition: awk '$3 > 100 {print $0}' file.

    Use built-in variables: NR (line number), NF (number of fields).

    Examples:
    bash
    
    awk '{print $1, $3}' data.txt          # Print 1st and 3rd columns
    awk '$3 > 100 {print $0}' data.txt     # Print lines where 3rd column > 100
    awk -F: '{print $1}' /etc/passwd       # Print usernames (1st column) from /etc/passwd

4. sed – Stream Editor
    Purpose: Perform text transformations on an input stream (file or pipeline).

    Common Commands:
    Substitute text: sed 's/old/new/' file.

    Delete lines: sed '5d' file (delete line 5).

    Print specific lines: sed -n '10,20p' file (print lines 10–20).

    Examples:
    bash
    
    sed 's/foo/bar/' file.txt          # Replace "foo" with "bar" in file.txt
    sed 's/foo/bar/g' file.txt         # Replace all occurrences of "foo" with "bar"
    sed '2d' file.txt                  # Delete the 2nd line
    sed -n '5,10p' file.txt            # Print lines 5 to 10

5. strace – Trace System Calls
    Purpose: Trace system calls and signals of a running process.

    Common Options:
    strace command: Trace a command.

    strace -p PID: Attach to a running process.

    strace -e trace=open,read: Trace specific system calls.

    strace -o output.txt: Save output to a file.

    Examples:
    bash
    
    strace ls                          # Trace system calls of `ls`
    strace -p 1234                     # Attach to process with PID 1234
    strace -e trace=open my_program    # Trace only `open` system calls
    strace -o log.txt my_program       # Save output to log.txt

6. Find files by name
    find /var/www -name '*.css'
        This will print out the full path/filename to all files under /var/www that end in .css. Example output:
    /var/www/html/text-cursor.css
    /var/www/html/style.css
    For more info:
    man find

Hands-On Practice
    ls:

        Navigate to /etc and list all files in long format, including hidden files.

        Recursively list files in /var/log.

    grep:

        Search for your username in /etc/passwd.

        Find all .conf files in /etc containing the word "network".

    awk:

        Print the 1st and 3rd columns of /etc/passwd.

        Filter lines in a CSV file where the 2nd column is greater than 50.

    sed:

        Replace all occurrences of "cat" with "dog" in a text file.

        Delete the 5th line of a file.

    strace:

        Trace the system calls of the ls command.

        Attach strace to a running process (use ps aux to find a PID).

Cheat Sheet 

    Command	    Purpose    	                Example

    ls   	List files	            ls -l /home
    grep	Search text	            grep "error" log.txt
    awk  	Text processing	        awk '{print $1}' file.txt
    sed	    Text substitution	    sed 's/foo/bar/' file.txt
    strace	Trace system calls	    strace ls





## ✅ 1. **awk** — Pattern Scanning and Processing

**`awk`** is used for **extracting**, **manipulating**, and **reporting** data in text files, often **line by line**.

### 📌 Basic Syntax:
```bash
awk 'pattern { action }' filename
```

### 🔹 Example 1: Print second column from a file
```bash
awk '{print $2}' data.txt
```

➡️ **Explanation**: Prints the **second field** (column) from each line (space/tab separated by default).

### 🔹 Example 2: Print lines where the value in column 3 is greater than 100
```bash
awk '$3 > 100' data.txt
```

➡️ **Explanation**: Filters and prints only those lines where the **third column** is greater than 100.

### 🔹 Example 3: Sum of column 2
```bash
awk '{sum += $2} END {print "Total:", sum}' data.txt
```

➡️ **Explanation**: Calculates and prints the **sum of the second column**.

---

## ✅ 2. **sed** — Stream Editor (for Text Manipulation)

**`sed`** is a **stream editor** used for **finding**, **substituting**, **inserting**, and **deleting** text in files or input streams.

### 📌 Basic Syntax:
```bash
sed 'command' filename
```

### 🔹 Example 1: Replace 'apple' with 'orange'
```bash
sed 's/apple/orange/' file.txt
```

➡️ **Explanation**: Replaces the first occurrence of 'apple' with 'orange' in each line.

### 🔹 Example 2: Replace all 'apple' with 'orange' globally
```bash
sed 's/apple/orange/g' file.txt
```

➡️ **Explanation**: Replaces **all occurrences** of 'apple' with 'orange' in each line.

### 🔹 Example 3: Delete empty lines
```bash
sed '/^$/d' file.txt
```

➡️ **Explanation**: Removes all **empty lines** from the file.

### 🔹 Example 4: Print only line number 3
```bash
sed -n '3p' file.txt
```

➡️ **Explanation**: Prints only **line number 3**.

---

## ✅ 3. **strace** — Trace System Calls

**`strace`** is used for **debugging** and **monitoring system calls** made by a program.

### 📌 Basic Syntax:
```bash
strace command
```

### 🔹 Example 1: Trace `ls` command
```bash
strace ls
```

➡️ **Explanation**: Shows all **system calls** made during execution of `ls`.

### 🔹 Example 2: Trace file access attempts
```bash
strace -e openat ls
```

➡️ **Explanation**: Shows only `openat` system calls (file open attempts).

### 🔹 Example 3: Trace a running process (by PID)
```bash
strace -p 1234
```

➡️ **Explanation**: Attaches to process with PID `1234` to trace its system calls.

### 🔹 Example 4: Write trace output to a file
```bash
strace -o trace.log ls
```

➡️ **Explanation**: Saves the `strace` output of `ls` into `trace.log`.

---

## 💡 Summary Table

| Tool   | Purpose                           | Example                                    |
|-------|----------------------------------|--------------------------------------------|
| **awk**  | Text extraction/processing        | `awk '{print $1, $3}' file.txt`             |
| **sed**  | Text substitution/editing        | `sed 's/foo/bar/g' file.txt`                |
| **strace** | Trace system calls (debugging) | `strace -e openat ls`                       |

---

If you want, I can give **real file examples** to practice on or combine these tools in **one-liners**. Want to see that? 🚀