# delete all the .exe files in the current directory and all subdirectories
import os
import sys

def cleanup(path):
    if os.path.isfile(path):
        if path.endswith(".exe"):
            os.remove(path)
            print("Deleted", path)
    else:
        for filename in os.listdir(path):
            cleanup(os.path.join(path, filename))
            
if __name__ == "__main__":
    cleanup(sys.argv[1] if len(sys.argv) > 1 else ".")
    
# Passing Github