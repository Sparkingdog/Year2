import time
while True:
    t = time.localtime()
    hour = t.tm_hour
    minute = t.tm_min
    sec = t.tm_sec
    print(f"{hour}:{minute}:{sec}")
    time.sleep(1)
