### Run bench marks ###
import subprocess
import sys
from threading import Timer

def run(param, timeout_sec):
  proc = subprocess.Popen(param, stdout=subprocess.PIPE, 
    stderr=subprocess.PIPE)
  kill_proc = lambda p: p.kill()
  timer = Timer(timeout_sec, kill_proc, [proc])
  try:
    timer.start()
    stdout,stderr = proc.communicate()
  finally:
    timer.cancel()

solverpath = "../Debug/solver.exe"
timeout = 1000
benchmarklist = ["quinn.cnf", "simplest.cnf", "test.cnf"]
paramlist = [[solverpath, "-f", x] for x in benchmarklist]
for param in paramlist:
	run(param, timeout)
	
