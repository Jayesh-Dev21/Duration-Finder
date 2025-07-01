CC = gcc
CFLAGS = -Wall 

TARGET = app

SRC = *.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
