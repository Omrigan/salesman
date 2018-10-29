import subprocess
import os
for path in os.listdir("solutions"):
    print("\n---------TESTING STARTED------\n")
    print(path + '\n')
    p = path[:path.find(".")]
    bashCommand = "make score " + p
    process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
    output, error = process.communicate()