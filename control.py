import subprocess
from time import sleep
exec(open('odczytZbazy.py').read())
<<<<<<< HEAD
sleep(5)
=======
sleep(1)
>>>>>>> d9fb227b2722a12bd62c5b3e6ac393f96c2ac13c
subprocess.Popen('./main')
sleep(5)
exec(open('zapisDObazy.py').read())