
all:a.out b.out c.out d.out
a.out:test_mongo.cpp
	g++ --std=c++11 test_mongo.cpp -o a.out \
		-I/usr/local/include/mongocxx/v_noabi \
		-I/usr/local/include/bsoncxx/v_noabi \
		-L/usr/local/liu -lmongocxx -lbsoncxx
	
b.out:test_api.cpp
	g++ --std=c++11 test_api.cpp -o b.out \
		-I/usr/local/include/mongocxx/v_noabi \
		-I/usr/local/include/bsoncxx/v_noabi \
		-L/usr/local/liu -lmongocxx -lbsoncxx

c.out:test_insert.cpp
	g++ --std=c++11 test_insert.cpp -o c.out \
		-I/usr/local/include/mongocxx/v_noabi \
		-I/usr/local/include/bsoncxx/v_noabi \
		-L/usr/local/liu -lmongocxx -lbsoncxx

d.out:test_find.cpp
	g++ --std=c++11 test_find.cpp -o d.out \
		-I/usr/local/include/mongocxx/v_noabi \
		-I/usr/local/include/bsoncxx/v_noabi \
		-L/usr/local/liu -lmongocxx -lbsoncxx

