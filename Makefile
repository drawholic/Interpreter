
CXX = g++
CXX_FLAGS = -c -I include/ 

BUILD_DIR = build
SRC_DIR = src

OBJS = ${BUILD_DIR}/Interpreter.o \
		${BUILD_DIR}/NonTerminal.o \
		${BUILD_DIR}/Terminal.o \
		${BUILD_DIR}/Parser.o \
		${BUILD_DIR}/Scanner.o \
		${BUILD_DIR}/AbstractExpression.o \

SRCS = ${SRC_DIR}/Interpreter.cpp \
		${SRC_DIR}/NonTerminal.cpp \
		${SRC_DIR}/Terminal.cpp \
		${SRC_DIR}/Parser.cpp \
		${SRC_DIR}/Scanner.cpp \
		${SRC_DIR}/AbstractExpression.cpp


${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

all: ${BUILD_DIR}/main

${BUILD_DIR}/main: ${SRC_DIR}/main.cpp ${OBJS}
	${CXX} -g -I include/ $^ -o $@

${BUILD_DIR}/Interpreter.o: ${SRC_DIR}/Interpreter.cpp ${BUILD_DIR}/Scanner.o ${BUILD_DIR}/Parser.o
	${CXX} ${CXX_FLAGS} $^ -o $@

${BUILD_DIR}/Scanner.o: ${SRC_DIR}/Scanner.cpp ${BUILD_DIR}/NonTerminal.o ${BUILD_DIR}/Terminal.o
	${CXX} ${CXX_FLAGS} $^ -o $@

${BUILD_DIR}/Parser.o: ${SRC_DIR}/Parser.cpp ${BUILD_DIR}/NonTerminal.o ${BUILD_DIR}/Terminal.o
	${CXX} ${CXX_FLAGS} $^ -o $@

${BUILD_DIR}/NonTerminal.o: ${SRC_DIR}/NonTerminal.cpp  ${BUILD_DIR}/AbstractExpression.o
	${CXX} ${CXX_FLAGS} $^ -o $@

${BUILD_DIR}/Terminal.o: ${SRC_DIR}/Terminal.cpp ${BUILD_DIR}/AbstractExpression.o
	${CXX} ${CXX_FLAGS} $^ -o $@

${BUILD_DIR}/AbstractExpression.o: ${SRC_DIR}/AbstractExpression.cpp
	${CXX} ${CXX_FLAGS} $^ -o $@

