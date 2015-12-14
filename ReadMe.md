------Names of all the other files submitting and brief description
1. test.sh---a sh file you can use to test my program
2. Documentation.txt---description of the overall design of the interpreter and how I tested the interpreter


------Instructions about how to compile and run the project
How to run my program?
	bash: $ make

How te test my program?
There are two ways to test my program.
1. By runing sh file
	bash: $ sh test.sh
2. By typing command in bash
	bash: $ bin/Interpreter codefile_name datafile_name outfile_name (the 2nd parameter is optional)
	For Example:
	bash: $ bin/Interpreter t1.code t1.data t1.out

------Special issues to remember during compilation or execution
1. DO NOT use redirection IO (< or >) in testing my program
	The interpreter is using commandline parameters to get the input/output file paths.
2. The 2nd paramter reserved for the input data file is optional
	bash: $ bin/Interpreter bad1.code bad1.out

How to clean my program in order to recompile it?
bash: $ make clean


Chuan, thank you very much for your grading.
Any question on my project, feel free to contact me @ (614)-721-9374.
Best regards.
										Zhenyu Wu
