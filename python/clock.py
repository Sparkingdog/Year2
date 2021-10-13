import time
while True:
    t = time.localtime()
    hour = t.tm_hour
    mininute = t.tm_min
    sec = t.tm_sec
    print(f"{hour}:{mininute}:{sec}")
    time.sleep(1)
