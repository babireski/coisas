cut:
	@g++ basics/cut.cpp -o cut
	@./cut
	@del cut.exe	

fibonacci:
	@g++ basics/fibonacci.cpp -o fibonacci
	@./fibonacci
	@del fibonacci.exe