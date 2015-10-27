# Markov [C++]

A simple Markov Chain experiment. 

COMPILATION:
  - Only requires an up-to-date C++11 compliant compiler.
  - Run the makefile to compile completely.

RUNNING:
  - To run my chainer, simply run the program with the desired plaintext file input.

USAGE:
	- ./markov [input_file]
		-+ Uses default database to seed histogram,
		-  then injects new data from the given file.	
	
	- ./markov -altdb [input_file] [desired_database]
		-+ If [desired_database] exists, will use it to seed
		-  historgram. If [desired_database] doesn't exist,
		-  it will be created.

	- ./markov -nodb [input_file]
		-+ No saved histogram is used/updated. Uses
		-  only the given file to create a histogram.

	- ./markov -dbonly
		-+ Generates output using only the default
		-  database's saved histogram.

	- ./markov -dbonly [desired_database]
		-+ Generates output using the indicated
		-  database's histogram.
  
  - To output to a file, use a redirect in your terminal program.
