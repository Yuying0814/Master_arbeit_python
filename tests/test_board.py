import serial

def test_board():
    ser = serial.Serial(
        port="COM5",
        baudrate=115200,
        timeout=1
    )

    while True:
        line = ser.readline().decode("utf-8", errors="ignore").strip()
        if line:
            print(line)

if __name__ == "__main__":
    test_board()
