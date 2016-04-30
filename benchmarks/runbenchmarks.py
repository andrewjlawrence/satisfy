### Run benchmarks ###
import subprocess
import sys
from threading import Timer,Thread

def run(param, timeout_sec):
    print("Starting thread")
    proc = subprocess.Popen(param, stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE)
    kill_proc = lambda p: p.kill()
    timer = Timer(timeout_sec, kill_proc, [proc])
    try:
        timer.start()
        stdout, stderr = proc.communicate()
        print("benchmark: " + param[2])
        print(stdout.decode())
    finally:
        timer.cancel()

solverpath = "../Debug/solver.exe"
timeout = 10000
benchmarklist = ["quinn.cnf",
                 # "simplest.cnf",
                 # "test.cnf",
                 "PHOLE-UNSAT/hole6.cnf",
                 "AIM-3SAT-MIXED/aim-50-1_6-no-1.cnf",
                 "AIM-3SAT-MIXED/aim-50-1_6-yes1-1.cnf"
                 ]
paramlist = [[solverpath, "-f", x] for x in benchmarklist]
if __name__ == "__main__":
    for param in paramlist:
        thread = Thread(target = run, args = (param, timeout))
        thread.start()
    print("Finished script")
