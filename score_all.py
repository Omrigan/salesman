import subprocess
import os
bashCommand = "make build-scoring"
process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
output, error = process.communicate()
for path in os.listdir("solutions"):
    print("\n---------TESTING STARTED------\n")
    print(path + '\n')
    p = path[:path.find(".")]
    bashCommand = "./score {}".format(p)
    print(bashCommand)
    process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
    output, error = process.communicate()