#!/usr/bin/env python3
import subprocess
from time import sleep
from datetime import timedelta
import datetime

last = datetime.datetime.now() - timedelta(minutes=2)
while True:
    teraz = datetime.datetime.now()
    if teraz > last + timedelta(seconds=30):
        last = datetime.datetime.now()
        exec(open('/var/www/html/Analiza/odczytZbazy.py').read())
        #sleep(5)
        p = subprocess.Popen('/var/www/html/Analiza/main')
        sleep(5)
        p.terminate()
        exec(open('/var/www/html/Analiza/zapisDObazy.py').read())
    sleep(1)
