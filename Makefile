CC_EXEC = g++
CC_FLASGS = -g

CC = ${CC_EXEC} ${CC_FLASGS}


BUILD_DR = build


all: main.out

main.out: ${BUILD_DR}/snapp.o ${BUILD_DR}/driver.o ${BUILD_DR}/travel.o ${BUILD_DR}/mission.o ${BUILD_DR}/timemission.o ${BUILD_DR}/distancemission.o ${BUILD_DR}/countmission.o
	${CC} ${BUILD_DR}/snapp.o ${BUILD_DR}/driver.o ${BUILD_DR}/travel.o ${BUILD_DR}/mission.o ${BUILD_DR}/timemission.o ${BUILD_DR}/distancemission.o ${BUILD_DR}/countmission.o -o main.out

${BUILD_DR}/snapp.o: snapp.cpp travel.hpp mission.hpp timemission.hpp distancemission.hpp countmission.hpp driver.hpp
	${CC} -c snapp.cpp -o ${BUILD_DR}/snapp.o

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

clean:
	rm -rf build/ && mkdir -p build