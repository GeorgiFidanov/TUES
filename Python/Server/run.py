import os
import subprocess
import time

# Execute the first file (interface.py.py)
subprocess.run(['python', 'DB_interface.py'], check=True)

# Validate the server file
svr = 'C:/Users/jojo/Documents/TUES/Python/Server/server.py'
assert os.path.isfile(svr)

# Start the server in a new terminal window
subprocess.Popen(['cmd', '/c', 'start', 'python', svr])

# Add a delay if needed to allow the server to start listening
time.sleep(1)

# Validate the server file
clnt = 'C:/Users/jojo/Documents/TUES/Python/Server/client.py'
assert os.path.isfile(clnt)

# Execute the third file (client.py) in a new terminal window
subprocess.Popen(['cmd', '/c', 'start', 'python', clnt])
