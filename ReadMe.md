------Names of all the other files submitting and brief description<br />
1. test.sh---a sh file you can use to test my program<br />
2. Documentation.txt---description of the overall design of the interpreter and how I tested the interpreter<br />


------Instructions about how to compile and run the project<br />
How to compile my program?<br />
	bash: $ make<br />
<br />
How te run my program?<br />
There are two ways to run my program.<br />
1. By runing sh file<br />
	bash: $ sh test.sh<br />
2. By typing command in bash<br />
	bash: $ bin/Interpreter codefile_name datafile_name outfile_name (the 2nd parameter is optional)<br />
	For Example:<br />
	bash: $ bin/Interpreter t1.code t1.data t1.out<br />

------Special issues to remember during compilation or execution<br />
1. DO NOT use redirection IO (< or >) in testing my program<br />
	The interpreter is using commandline parameters to get the input/output file paths.<br />
2. The 2nd paramter reserved for the input data file is optional<br />
	bash: $ bin/Interpreter bad1.code bad1.out<br />
<br />
How to clean my program in order to recompile it?<br />
bash: $ make clean<br />
