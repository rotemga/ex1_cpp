$(TARGET)
TARGET := simulator
CFLAGS := -std=c++11 -O2 -Wall -pedantic -pthread
O_FILES:= main.o Battery.o House.o OurSensor.o Point.o RandomAlgorithm.o Robot.o Score.o SimpleIniFileParser.o Simulator.o FuncForMain.o




$(TARGET): $(O_FILES)
	g++ -o $(TARGET) $(O_FILES) -std=c++11 -O2 -Wall -pedantic -pthread -L/usr/local/boost/boost_1_50_0/stage/lib -lboost_filesystem -lboost_system

main.o: main.cpp FuncForMain.h
	g++ -c $(CFLAGS) $*.cpp -L/usr/local/boost/boost_1_50_0/stage/lib -lboost_filesystem -lboost_system
	
FuncForMain.o: FuncForMain.cpp FuncForMain.h House.h Simulator.h RandomAlgorithm.h SimpleIniFileParser.h
	g++ -c $(CFLAGS) $*.cpp -L/usr/local/boost/boost_1_50_0/stage/lib -lboost_filesystem -lboost_system

Battery.o: Battery.cpp Battery.h
	g++ -c $(CFLAGS) $*.cpp 

House.o: House.cpp House.h SensorInformation.h
	g++ -c $(CFLAGS) $*.cpp 

OurSensor.o: OurSensor.cpp OurSensor.h AbstractSensor.h House.h
	g++ -c $(CFLAGS) $*.cpp 

Point.o: Point.cpp Point.h Direction.h
	g++ -c $(CFLAGS) $*.cpp 

RandomAlgorithm.o: RandomAlgorithm.cpp RandomAlgorithm.h AbstractAlgorithm.h OurSensor.h
	g++ -c $(CFLAGS) $*.cpp 

Robot.o: Robot.cpp Robot.h House.h AbstractAlgorithm.h AbstractSensor.h OurSensor.h Battery.h Score.h
	g++ -c $(CFLAGS) $*.cpp 

Score.o: Score.cpp Score.h
	g++ -c $(CFLAGS) $*.cpp 

SimpleIniFileParser.o: SimpleIniFileParser.cpp SimpleIniFileParser.h
	g++ -c $(CFLAGS) $*.cpp 

Simulator.o: Simulator.cpp Simulator.h House.h Score.h AbstractAlgorithm.h AbstractSensor.h OurSensor.h Robot.h Battery.h Point.h
	g++ -c $(CFLAGS) $*.cpp 





clean:
	-rm $(TARGET) $(O_FILES)