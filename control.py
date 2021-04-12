#!/usr/bin/env python3
import subprocess
from time import sleep
exec(open('/var/www/html/Analiza/odczytZbazy.py').read())
sleep(5)
subprocess.Popen('/var/www/html/Analiza/main')
sleep(5)
exec(open('/var/www/html/Analiza/zapisDObazy.py').read())
