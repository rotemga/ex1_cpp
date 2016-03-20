TARGET := ex1
CFLAGS :=g++ -std=c++11 -O2 -Wall -pedantic -pthread
O_FILES:= main.o Battery.o House.o OurSensor.o Point.o RandomAlgorithm.o Robot.o Score.o SimpleIniFileParser.o Simulator.o 


all: $(TARGET)


$(TARGET): $(O_FILES)
	g++ -o $(TARGET) $(O_FILES) -std=c++11 -O2 -Wall -pedantic -pthread -lboost_filesystem

main.o: main.c House.h Simulator.h RandomAlgorithm.h SimpleIniFileParser.h
	g++ -cpp $(CFLAGS) $*.cpp -lboost_filesystem

Battery.o: Battery.cpp Battery.h
	g++ -cpp $(CFLAGS) $*.cpp 

House.o: House.cpp House.h SensorInformation.h
	g++ -cpp $(CFLAGS) $*.cpp 

OurSensor.o: OurSensor.cpp OurSensor.h AbstractSensor.h House.h
	g++ -cpp $(CFLAGS) $*.cpp 

Point.o: Point.cpp Point.h Direction.h
	g++ -cpp $(CFLAGS) $*.cpp 

RandomAlgorithm.o: RandomAlgorithm.cpp RandomAlgorithm.h AbstractAlgorithm.h OurSensor.h
	g++ -cpp $(CFLAGS) $*.cpp 

Robot.o: Robot.cpp Robot.h House.h AbstractAlgorithm.h AbstractSensor.h OurSensor.h Battery.h Score.h
	g++ -cpp $(CFLAGS) $*.cpp 

Score.o: Score.cpp Score.h
	g++ -cpp $(CFLAGS) $*.cpp 

SimpleIniFileParser.o: SimpleIniFileParser.cpp SimpleIniFileParser.h
	g++ -cpp $(CFLAGS) $*.cpp 

Simulator.o: Simulator.cpp Simulator.h House.h Score.h AbstractAlgorithm.h AbstractSensor.h OurSensor.h Robot.h Battery.h Point.h
	g++ -cpp $(CFLAGS) $*.cpp 





clean:
	-rm $(TARGET) $(O_FILES)
