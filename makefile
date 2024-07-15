compile:
	g++ pwdshort.cpp -o a.out
install:
	mkdir -p ~/.local/bin
	g++ pwdshort.cpp -o ~/.local/bin/pwdshort
