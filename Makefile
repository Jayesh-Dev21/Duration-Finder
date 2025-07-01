CC = gcc
CFLAGS = -Wall 

TARGET = duration_finder

SRC = *.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
