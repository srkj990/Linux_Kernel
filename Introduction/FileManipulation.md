## Files and directories (another name for folders) are at the heart of Linux, so being able to create, view, move, and
delete them from the command line is very important and quite powerful. These file manipulation commands allow
you to perform the same tasks that a graphical file explorer would perform.


1. Create an empty text file called myFile:

touch myFile

2. Rename myFile to myFirstFile:

mv myFile myFirstFile

3. View the contents of a file:

cat myFirstFile

4. View the content of a file with pager (one screenful at a time):

less myFirstFile

5. View the first several lines of a file:

head myFirstFile

6. View the last several lines of a file:

tail myFirstFile

7. Edit a file:GoalKicker.com – Linux® Notes for Professionals 8

vi myFirstFile

8. See what files are in your current working directory:

ls

9. Create an empty directory called myFirstDirectory:

mkdir myFirstDirectory

10. Create multi path directory: (creates two directories, src and myFirstDirectory)

mkdir -p src/myFirstDirectory

11. Move the file into the directory:

mv myFirstFile myFirstDirectory/

12. You can also rename the file:

user@linux-computer:~$ mv myFirstFile secondFileName

13. Change the current working directory to myFirstDirectory:

cd myFirstDirectory

14. Delete a file:

rm myFirstFile

15. Move into the parent directory (which is represented as ..):

cd ..

16. Delete an empty directory:

rmdir myFirstDirectory

17. Delete a non-empty directory (i.e. contains files and/or other directories):

rm -rf myFirstDirectory

Make note that when deleting directories, that you delete ./ not / that will wipe your whole filesystem