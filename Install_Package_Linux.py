import json
import os

def read_json():
    with open("Requirements.json") as json_data:
        packages = json.load(json_data)

    return packages

def install_pkg(packages):
    successp = []
    failp = []
    for i in packages["Dependencies"]:
        cdd = "pip install " + i +"==" + packages["Dependencies"][i]
        print (cdd)
        ret = os.system(cdd)
        if (ret == 0):
            successp.append(i)
        else:
            failp.append(i)
        
    return successp, failp
    


packages = read_json()
successp, failp = install_pkg(packages)


print ("Successful Packages:")
for i in successp:
    print (i)

print ("Un-Successful Packages:")
for i in failp:
    print (i)
