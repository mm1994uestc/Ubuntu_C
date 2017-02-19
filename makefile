# 注意我使用了gcc的编译参数-fno-builtin才避免出现conflicting types for built-in function ‘XXX’的问题！
Files = main.c mystack.c mystack.h myagorithm.c myagorithm.h
main.o:${Files}
	gcc -o main.o ${Files} -fno-builtin -lm
clean:
	rm main.o
