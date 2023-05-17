CC_EXEC = g++
CC_FLASGS = -g

CC = ${CC_EXEC} ${CC_FLASGS}


BUILD_DR = build

all: main.out

main.out: ${BUILD_DR}/functions.o ${BUILD_DR}/handle_inputs.o ${BUILD_DR}/driver.o ${BUILD_DR}/travel.o ${BUILD_DR}/mission.o ${BUILD_DR}/timemission.o ${BUILD_DR}/distancemission.o ${BUILD_DR}/countmission.o
	${CC} ${BUILD_DR}/functions.o ${BUILD_DR}/handle_inputs.o ${BUILD_DR}/driver.o ${BUILD_DR}/travel.o ${BUILD_DR}/mission.o ${BUILD_DR}/timemission.o ${BUILD_DR}/distancemission.o ${BUILD_DR}/countmission.o -o main.out

${BUILD_DR}/functions.o: functions.cpp travel.hpp mission.hpp timemission.hpp distancemission.hpp countmission.hpp driver.hpp
	${CC} -c functions.cpp -o ${BUILD_DR}/functions.o

${BUILD_DR}/driver.o: driver.cpp driver.hpp mission.hpp travel.hpp
	${CC} -c driver.cpp -o ${BUILD_DR}/driver.o

${BUILD_DR}/travel.o: travel.cpp
	${CC} -c travel.cpp -o ${BUILD_DR}/travel.o

${BUILD_DR}/mission.o: mission.cpp
	${CC} -c mission.cpp -o ${BUILD_DR}/mission.o

${BUILD_DR}/timemission.o: timemission.cpp mission.hpp 
	${CC} -c timemission.cpp -o ${BUILD_DR}/timemission.o

${BUILD_DR}/distancemission.o: distancemission.cpp mission.hpp
	${CC} -c distancemission.cpp -o ${BUILD_DR}/distancemission.o

${BUILD_DR}/countmission.o: countmission.cpp mission.hpp
	${CC} -c countmission.cpp -o ${BUILD_DR}/countmission.o

${BUILD_DR}/handle_inputs.o : handle_inputs.cpp functions.hpp
	${CC} -c handle_inputs.cpp -o ${BUILD_DR}/handle_inputs.o

clean:
	rm -rf build/ && mkdir -p build