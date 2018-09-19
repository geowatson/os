n=20
while [[ $n != 0 ]]; do
	# critical region start
	if ln ex2.file ex2.file.lock 
	then
		expr `tail -1 ex2.file` + 1 >> ex2.file
		n=$(($n - 1))
		rm ex2.file.lock
	else
		sleep 0.1
	# critical region end
	fi
done
