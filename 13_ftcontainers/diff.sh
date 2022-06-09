diff myContainers.txt stlContainers.txt > difference.txt
error=$?
if [ $error -eq 2 ]
then
   echo "There was something wrong with the diff command"
elif [ $error -eq 1 ]
then
   echo "files differ - see difference.txt"
else
   echo "files are the same file"
fi
