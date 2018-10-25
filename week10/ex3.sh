echo "echo" > _ex3.txt
chmod 666 _ex3.txt
ls -l _ex3.txt > ex3.txt

chmod 707 _ex3.txt
ls -l _ex3.txt >> ex3.txt

chmod 660 _ex3.txt
ls -l _ex3.txt >> ex3.txt
rm _ex3.txt
