### Run benchmarks ###
import subprocess
import sys
import threading
from threading import Timer

def run(param, timeout_sec):
  proc = subprocess.Popen(param, stdout=subprocess.PIPE, 
    stderr=subprocess.PIPE)
  kill_proc = lambda p: p.kill()
  timer = Timer(timeout_sec, kill_proc, [proc])
  try:
    timer.start()
    stdout,stderr = proc.communicate()
    print("benchmark: " + param[0])
    print(stdout.decode())
  finally:
    timer.cancel()

solverpath = "../Debug/solver.exe"
timeout = 10000
benchmarklist = ["quinn.cnf",
                 #"simplest.cnf",
                 #"test.cnf",
                 "PHOLE-UNSAT/hole6.cnf",
                 "AIM-3SAT-MIXED/aim-50-1_6-no-1.cnf",
                 "AIM-3SAT-MIXED/aim-50-1_6-yes1-1.cnf"
                ]
paramlist = [[solverpath, "-f", x] for x in benchmarklist]
for param in paramlist:
	threading.start_new_thread(run,(param, timeout))
	
