import subprocess
from time import sleep
exec(open('odczytZbazy.py').read())
sleep(5)
subprocess.Popen('./main')
sleep(5)
exec(open('zapisDObazy.py').read())